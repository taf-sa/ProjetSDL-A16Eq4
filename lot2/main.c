#include "ennemi.h"
#include "jeu.h"
#include <SDL/SDL.h>
#include <string.h>

#define NUM_SPRITES 100
#define MAX_SPEED 1

int main(int argc, char* argv[])
{
    int nbGameObjects = 0;
    /** int* gameObjects; // array of all game objects */
    /** Ennemi* EnnemiOjbjects; // array of enemies */
    void* gameObjects[10];
    Ennemi ennemis[10];
    Ennemi e;
    SDL_Surface* fenetre;
    int i = 0, done, width, height;
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

    atexit(clean);
    fenetre = init(width, height, video_bpp, videoflags, false);

    initEnnemi(&e);
    gameObjects[i] = &e;

    Uint32 color = SDL_MapRGB(e.image->format, 0, 0, 0);
    frames = 0;
    done = 0;
    afficherEnnemi(e, fenetre);

    while (!done) {
        ++frames;
        e.currentFrame = frames;
        then = SDL_GetTicks();
        handleEvents(&done, fenetre, video_bpp, videoflags);
        /** update(gameObjects); */
        /** render(gameObjects, fenetre); */
        animerEnnemi(&e);
        SDL_FillRect(fenetre, NULL, color);
        afficherEnnemi(e, fenetre);
        getFramerate(then, frames);
        SDL_Delay(100);
    }

    SDL_FreeSurface(fenetre);
    return 0;
}
