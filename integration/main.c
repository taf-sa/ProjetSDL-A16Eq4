#include "jeu.h"

int main(int argc, char* argv[])
{
    void* gameObjects[10];
    stateVariables sv;

    atexit(clean);
    sv.fenetre = init(argc, argv, &sv);

    while (!sv.done) {

        handleEvents(sv.fenetre, &sv);
        render(gameObjects, sv.fenetre);
        update(gameObjects, &sv);
    }

    freeSurfaces(&sv);
    return EXIT_SUCCESS;
}
