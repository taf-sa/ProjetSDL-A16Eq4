#include "background.h"
#include "jeu.h"

int main(int argc, char* argv[])
{
    void* gameObjects[10];
    stateVariables sv;
    background b;

    atexit(clean);
    sv.fenetre = init(argc, argv, &sv);

    initialiser_background(&b);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);

    while (!sv.done) {

        handleEvents(sv.fenetre, &sv);
        render(gameObjects, sv.fenetre);
        update(gameObjects, &sv);

        afficher_background(b, sv.fenetre);
    }

    freeSurfaces(&sv);
    return EXIT_SUCCESS;
}