#include "ennemi.h"
#include "jeu.h"
#include <SDL/SDL.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int nbGameObjects = 0;
    /** int* gameObjects; // array of all game objects */
    /** Ennemi* EnnemiOjbjects; // array of enemies */
    void* gameObjects[10];
    Ennemi ennemis[10];
    Ennemi e;
    int i = 0;
    Uint32 then, frames;
    SDL_Surface* fenetre;
    stateVariables sv;

    atexit(clean);
    fenetre = init(argc, argv, &sv);

    initEnnemi(&e);
    gameObjects[i] = &e;

    Uint32 color = SDL_MapRGB(e.image->format, 0, 0, 0);
    frames = 0;
    afficherEnnemi(e, fenetre);

    while (!sv.done) {
        ++frames;
        e.currentFrame = frames;
        then = SDL_GetTicks();
        handleEvents(fenetre, &sv);
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
