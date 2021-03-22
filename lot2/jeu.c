#include "jeu.h"
#include "ennemi.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdbool.h>

SDL_Surface* init(int w, int h, Uint8 video_bpp, Uint32 videoFlags, bool fullscreen)
{
    SDL_Surface* screen;
    Uint32 flags;
    int initted;

    printf("Initializing SDL.\n");

    if ((SDL_Init(SDL_INIT_EVERYTHING) < 0)) {
        fprintf(stderr, "Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }
    printf("SDL initialized.\n");

    // load support for the JPG and PNG image formats
    flags = IMG_INIT_JPG | IMG_INIT_PNG;
    initted = IMG_Init(flags);
    if ((initted & flags) != flags) {
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
    }

    if (fullscreen)
        videoFlags |= SDL_FULLSCREEN;

    screen = SDL_SetVideoMode(w, h, video_bpp, videoFlags);

    if (screen == NULL) {
        fprintf(stderr, "Couldn't set %dx%dx%d video mode: %s\n",
            w, h, video_bpp, SDL_GetError());
        exit(-1);
    }

    // TODO This code produces unexpected results for some reason.
    printf("Set%s %dx%dx%d mode\n",
        (screen->flags & SDL_FULLSCREEN) ? " fullscreen" : "",
        screen->w, screen->h, screen->format->BitsPerPixel);
    printf("(video surface located in %s memory)\n",
        (screen->flags & SDL_HWSURFACE) ? "video" : "system");
    if (screen->flags & SDL_DOUBLEBUF) {
        printf("Double-buffering enabled\n");
    }

    SDL_WM_SetCaption("Savior", "testIcon");

    return screen;
}

void clean()
{
    printf("Quitting SDL_image.\n");
    IMG_Quit();
    printf("Quiting SDL.\n");
    SDL_Quit();
    printf("Quiting....\n");
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

    /* Return the flags */
    return (flags);
}

void handleEvents(int* done, SDL_Surface* fenetre, Uint8 video_bpp, Uint32 videoflags)
{
    SDL_Event event;
    /* Check for events */
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            // is this working?
            SDL_WarpMouse(fenetre->w / 2, fenetre->h / 2);
            break;
        case SDL_KEYDOWN:
            /* Any keypress quits the app... */
            *done = 1;
            break;
        case SDL_VIDEORESIZE:
            // resizing the window
            fenetre = SDL_SetVideoMode(event.resize.w, event.resize.h, video_bpp, videoflags);
            break;
        case SDL_QUIT:
            *done = 1;
            break;

            break;
        }
    }
}

void getFramerate(Uint32 then, Uint32 frames)
{
    Uint32 now;
    /* Print out some timing information */
    now = SDL_GetTicks();
    if (now > then) {
        printf("%.0f frames per second\n",
            ((double)frames * 1000) / (now - then));
    }
}

void update(void* gameObjects[])
{
    for (int i = 0; i < 10; i++) {
        /** ((Ennemi*)(gameObjects[i]))->miseAJour(); */
    }
}

void render(void* gameObjects[], SDL_Surface* fenetre)
{
    SDL_Flip(fenetre);
    for (int i = 0; i < 10; i++) {
        /** ((Ennemi*)(gameObjects[i]))->draw(fenetre); */
    }
}
