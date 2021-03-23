#include "gameObjects.h"
#include "jeu.h"
#include <SDL/SDL_video.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int nbGameObjects = 0, i = 0;
    Uint32 then, frames;
    /** void* gameObjects; //malloc*/
    void* gameObjects[10];
    EnemyObject eo;
    stateVariables sv;

    atexit(clean);
    sv.fenetre = init(argc, argv, &sv);

    initEnemyObject(&eo);
    gameObjects[i++] = &eo;

    frames = 0;
    while (!sv.done) {
        ++frames;
        then = SDL_GetTicks();
        handleEvents(sv.fenetre, &sv);
        render(gameObjects, sv.fenetre);
        update(gameObjects, &sv);
        getFrameRate(then, frames);
    }

    SDL_FreeSurface(sv.fenetre);
    return 0;
}
