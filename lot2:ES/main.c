#include "gameObjects.h"
#include "jeu.h"
#include <SDL/SDL_video.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int nbGameObjects = 0, i = 0;
    int FPS = 60;
    int delayTime = (int)1000 / FPS;
    Uint32 frameStart, frames, frameTime, now;
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
        frameStart = SDL_GetTicks();

        handleEvents(sv.fenetre, &sv);
        render(gameObjects, sv.fenetre);
        update(gameObjects, &sv);

        // capping frame rate
        /** frameTime = SDL_GetTicks() - frameStart; */
        /** if (frameTime < delayTime) { */
        /**     SDL_Delay((int)(delayTime - frameTime)); */
        /** } */

        getFrameRate(frameStart, frames);
    }

    SDL_FreeSurface(sv.fenetre);
    return 0;
}
