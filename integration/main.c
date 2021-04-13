#include "background.h"
#include "gameObjects.h"
#include "jeu.h"

int main(int argc, char* argv[])
{
    int i = 0;
    void* gameObjects[10];
    EnemyObject eo;
    stateVariables sv;

    atexit(clean);
    sv.fenetre = init(argc, argv, &sv);

    initialiser_background(&sv.bg);
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);

    initEnemyObject(&eo);
    gameObjects[i++] = &eo;

    while (!sv.done) {

        handleEvents(&sv);
        render(gameObjects, sv);
        update(gameObjects, &sv);
    }

    cleanEnnemi(&eo.e);
    freeMemory(&sv);
    return EXIT_SUCCESS;
}
