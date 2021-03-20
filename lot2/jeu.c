#include "jeu.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdbool.h>

SDL_Surface* init(int w, int h, bool fullscreen)
{
    SDL_Surface* screen;
    int flags, initted;

    printf("Initializing SDL.\n");
    if ((SDL_Init(SDL_INIT_EVERYTHING) == -1)) {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
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

    flags = SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE;
    if (fullscreen)
        flags |= SDL_FULLSCREEN;

    screen = SDL_SetVideoMode(w, h, 32, flags);

    if (screen == NULL) {
        fprintf(stderr, "Couldn't set %dx%dx%d video mode: %s\n",
            w, h, 32, SDL_GetError());
        exit(1);
    }

    printf("Set%s %dx%dx%d mode\n",
        screen->flags & SDL_FULLSCREEN ? " fullscreen" : "",
        screen->w, screen->h, screen->format->BitsPerPixel);
    printf("(video surface located in %s memory)\n",
        (screen->flags & SDL_HWSURFACE) ? "video" : "system");
    if (screen->flags & SDL_DOUBLEBUF) {
        printf("Double-buffering enabled\n");
    }

    SDL_WM_SetCaption("SDL test window", "testwin");

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
