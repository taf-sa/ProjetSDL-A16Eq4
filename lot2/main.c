#include "ennemi.h"
#include "jeu.h"
#include <SDL/SDL.h>
#include <string.h>

#define NUM_SPRITES 100
#define MAX_SPEED 1

int main(int argc, char* argv[])
{
    Ennemi e;
    SDL_Surface* fenetre;
    SDL_Event event;
    int i, done, width, height;
    int numsprites, debug_flip;
    Uint8 video_bpp;
    Uint32 videoflags;
    Uint32 background;
    Uint32 then, now, frames;

    numsprites = NUM_SPRITES;
    videoflags = SDL_SWSURFACE | SDL_ANYFORMAT | SDL_DOUBLEBUF | SDL_RESIZABLE;
    width = 640;
    height = 480;
    video_bpp = 32;
    debug_flip = 0;

    while (argc > 1) {
        --argc;
        if (strcmp(argv[argc - 1], "-width") == 0) {
            width = atoi(argv[argc]);
            --argc;
        } else if (strcmp(argv[argc - 1], "-height") == 0) {
            height = atoi(argv[argc]);
            --argc;
        } else if (strcmp(argv[argc - 1], "-bpp") == 0) {
            video_bpp = atoi(argv[argc]);
            videoflags &= ~SDL_ANYFORMAT;
            --argc;
        } else if (strcmp(argv[argc], "-fast") == 0) {
            videoflags = fastestFlags(videoflags, width, height, video_bpp);
        } else if (strcmp(argv[argc], "-hw") == 0) {
            videoflags ^= SDL_HWSURFACE;
        } else if (strcmp(argv[argc], "-flip") == 0) {
            videoflags ^= SDL_DOUBLEBUF;
        } else if (strcmp(argv[argc], "-debugflip") == 0) {
            debug_flip ^= 1;
        } else if (strcmp(argv[argc], "-fullscreen") == 0) {
            videoflags ^= SDL_FULLSCREEN;
        } else if (isdigit(argv[argc][0])) {
            numsprites = atoi(argv[argc]);
        } else {
            fprintf(stderr,
                "Usage: %s [-bpp N] [-hw] [-flip] [-fast] [-fullscreen] [numsprites]\n",
                argv[0]);
            exit(1);
        }
    }

    //atexit(clean);
    fenetre = init(width, height, video_bpp, videoflags, false);

    initEnnemi(&e);
    afficherEnnemi(e, fenetre);

    frames = 0;
    then = SDL_GetTicks();
    done = 0;
    while (!done) {
        /* Check for events */
        ++frames;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                // is this working?
                SDL_WarpMouse(fenetre->w / 2, fenetre->h / 2);
                break;
            case SDL_KEYDOWN:
                /* Any keypress quits the app... */
                done = 1;
                break;
            case SDL_VIDEORESIZE:
                // resizing the window
                fenetre = SDL_SetVideoMode(event.resize.w, event.resize.h, video_bpp, videoflags);
                break;
            case SDL_QUIT:
                done = 1;
                break;
            default:
                break;
            }
        }
    }
    /** SDL_Delay(1000); */

    /* Print out some timing information */
    now = SDL_GetTicks();
    if (now > then) {
        printf("%2.2f frames per second\n",
            ((double)frames * 1000) / (now - then));
    }

    SDL_FreeSurface(fenetre);
    clean();
    return 0;
}
