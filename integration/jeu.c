#include "jeu.h"
#include "background.h"
#include "gameObjects.h"

#define NUM_SPRITES 100

SDL_Surface* init(int argc, char* argv[], stateVariables* sv)
{
    SDL_Surface* screen;
    Uint32 flags;
    int initted;

    printf("Initializing SDL...\n");

// SDL with X11 doesn't support HWSURFACE
#ifdef linux // Initialise SDL video system.
    putenv("SDL_VIDEODRIVER=dga"); // Try dga video driver
    fprintf(stderr, "WARNING: you must be root to use the DGA driver\n");
#endif
    if ((SDL_Init(SDL_INIT_EVERYTHING) < 0)) {
        fprintf(stderr, "DGA mode not available.\n");
        fprintf(stderr, "trying x11 (no Support for HWSURFACE)…\n");
#ifdef linux
        putenv("SDL_VIDEODRIVER=x11"); // Failover to x11 driver
#endif
        if ((SDL_Init(SDL_INIT_EVERYTHING) < 0)) {
            printf("Unable to initialise SDL: %s\n", SDL_GetError());
            exit(-1);
        }
    }

    printf("SDL initialized...\n");

    // load support for the JPG and PNG image formats
    flags = IMG_INIT_JPG | IMG_INIT_PNG;
    initted = IMG_Init(flags);
    if ((initted & flags) != flags) {
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
    {
        printf("%s", Mix_GetError());
    }
    sv->volume = MIX_MAX_VOLUME / 4;
    Mix_VolumeMusic(sv->volume);
    sv->musique = Mix_LoadMUS("ressources/music.mp3"); //Chargement de la musique
    Mix_PlayMusic(sv->musique, -1); //Jouer infiniment la musique

    initStateVariables(sv);

    handleArguments(argc, argv, sv);

    sv->icon = IMG_Load("ressources/icon.png");
    SDL_WM_SetIcon(sv->icon, NULL);
    SDL_WM_SetCaption("Savior", NULL);

    screen = SDL_SetVideoMode(sv->winWidth, sv->winHeight, sv->video_bpp, sv->videoFlags);
    /** screen = SDL_SetVideoMode(sv->winWidth, sv->winHeight, sv->video_bpp, sv->videoFlags); */

    if (screen == NULL) {
        fprintf(stderr, "Couldn't set %dx%dx%d video mode: %s\n",
            sv->winWidth, sv->winHeight, sv->video_bpp, SDL_GetError());
        exit(-1);
    }

    // sv->videoFlags & SDL_HWSURFACE is true but not screen->flags & SDL_HWSURFACE
    // SDL uses X11 video driver by default and it can't access video hardware
    printf("Set%s %dx%dx%d mode\n",
        (screen->flags & SDL_FULLSCREEN) ? " fullscreen" : "",
        screen->w, screen->h, screen->format->BitsPerPixel);
    printf("(video surface located in %s memory)\n",
        (screen->flags & SDL_HWSURFACE) ? "video" : "system");
    if (screen->flags & SDL_DOUBLEBUF) {
        printf("Double-buffering enabled\n");
    }

    return screen;
}

void update(void** gameObjects, stateVariables* sv)
{
    if (sv->winResized) {
        sv->winResized = false;
        sv->fenetre = SDL_SetVideoMode(sv->winWidth, sv->winHeight, sv->video_bpp, sv->videoFlags);
    }

    mettreAJourEnnemi(&((EnemyObject*)gameObjects[0])->e, gameObjects, *sv);
}

void render(void* gameObjects[], stateVariables sv)
{
    afficher_background(sv.bg, sv.fenetre);
    afficherEnnemi(((EnemyObject*)gameObjects[0])->e, sv.fenetre);

    if (SDL_Flip(sv.fenetre) == -1) {
        printf("Erreur: SDL_Flip() in render()");
    }
}

void clean()
{
    printf("Quitting SDL_mixer...");
    Mix_CloseAudio();
    printf("Quitting SDL_image...\n");
    IMG_Quit();
    printf("Quiting SDL...\n");
    SDL_Quit();
    printf("Quiting....\n");
}

void freeMemory(stateVariables* sv)
{
    Mix_FreeMusic(sv->musique);
    SDL_FreeSurface(sv->bg.afficher_background);
    SDL_FreeSurface(sv->icon);
    SDL_FreeSurface(sv->fenetre);
}

void getFrameRate(Uint32 then, Uint32 frames)
{
    Uint32 now, timeInterval, delay;
    double fps;

    now = SDL_GetTicks();
    timeInterval = now - then;
    delay = (Uint32)(((now / 300) % 10));
    fps = (double)frames * 1000 / timeInterval;

    if (timeInterval > 0 && delay == 1) {
        printf("%.0lf frames per second\n", fps);
    }
}

void initStateVariables(stateVariables* sv)
{
    sv->numsprites = NUM_SPRITES;
    sv->videoFlags = SDL_HWSURFACE | SDL_ANYFORMAT | SDL_DOUBLEBUF | SDL_RESIZABLE;
    sv->winWidth = CAMERA_W;
    sv->winHeight = CAMERA_H;
    sv->video_bpp = 32;
    sv->debug_flip = 0;
    sv->done = false;
}

/* This is a way of telling whether or not to use hardware surfaces */
Uint32 fastestFlags(Uint32 flags, int width, int height, int bpp)
{
    const SDL_VideoInfo* info;

    /* Hardware acceleration is only used in fullscreen mode */
    flags |= SDL_FULLSCREEN;

    /* Check for various video capabilities */
    info = SDL_GetVideoInfo();
    if (info->blit_hw_CC && info->blit_fill) {
        /* We use accelerated colorkeying and color filling */
        flags |= SDL_HWSURFACE;
    }
    /* If we have enough video memory, and will use accelerated
	   blits directly to it, then use page flipping.
	 */
    if ((flags & SDL_HWSURFACE) == SDL_HWSURFACE) {
        /* Direct hardware blitting without double-buffering
		   causes really bad flickering.
		 */
        if (info->video_mem * 1024 > (height * width * bpp / 8)) {
            flags |= SDL_DOUBLEBUF;
        } else {
            flags &= ~SDL_HWSURFACE;
        }
    }

    return (flags);
}

void handleArguments(int argc, char* argv[], stateVariables* sv)
{
    while (argc > 1) {
        --argc;
        if (strcmp(argv[argc - 1], "-width") == 0) {
            sv->winWidth = atoi(argv[argc]);
            --argc;
        } else if (strcmp(argv[argc - 1], "-height") == 0) {
            sv->winHeight = atoi(argv[argc]);
            --argc;
        } else if (strcmp(argv[argc - 1], "-bpp") == 0) {
            sv->video_bpp = atoi(argv[argc]);
            sv->videoFlags &= ~SDL_ANYFORMAT;
            --argc;
        } else if (strcmp(argv[argc], "-fast") == 0) {
            sv->videoFlags = fastestFlags(sv->videoFlags, sv->winWidth, sv->winHeight, sv->video_bpp);
        } else if (strcmp(argv[argc], "-hw") == 0) {
            sv->videoFlags ^= SDL_HWSURFACE;
        } else if (strcmp(argv[argc], "-flip") == 0) {
            sv->videoFlags ^= SDL_DOUBLEBUF;
        } else if (strcmp(argv[argc], "-debugflip") == 0) {
            sv->debug_flip ^= 1;
        } else if (strcmp(argv[argc], "-fullscreen") == 0) {
            sv->videoFlags ^= SDL_FULLSCREEN;
        } else if (isdigit(argv[argc][0])) {
            sv->numsprites = atoi(argv[argc]);
        } else {
            fprintf(stderr,
                "Usage: %s [-bpp N] [-hw] [-flip] [-fast] [-fullscreen] [numsprites]\n",
                argv[0]);
            exit(1);
        }
    }
}

void handleEvents(stateVariables* sv)
{
    SDL_Event event;
    int d;
    int pasavancement = 5;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            // is this working?
            SDL_WarpMouse(sv->fenetre->w / 2, sv->fenetre->h / 2);
            break;
        case SDL_VIDEORESIZE:
            // resize the window
            sv->winResized = true;
            sv->winWidth = event.resize.w;
            sv->winHeight = event.resize.h;
            break;
        case SDL_QUIT:
            sv->done = true;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                sv->done = true;
                break;
            case SDLK_LEFT:
                d = 1;
                scrolling(&sv->bg, d, pasavancement);
                if (sv->volume > 0) {
                    sv->volume--;
                }
                Mix_VolumeMusic(sv->volume);
                break;
            case SDLK_RIGHT:
                d = 0;
                scrolling(&sv->bg, d, pasavancement);
                if (sv->volume < 128) {
                    sv->volume++;
                }
                Mix_VolumeMusic(sv->volume);
                break;
            case SDLK_UP:
                d = 2;
                scrolling(&sv->bg, d, pasavancement);
                break;
            case SDLK_DOWN:
                d = 3;
                scrolling(&sv->bg, d, pasavancement);
                break;
            default:
                break;
            }
        }
        break;

    deflaut:
        break;
    }
}
