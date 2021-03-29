#include "gameObjects.h"

#define TICK_INTERVAL 30

int main(int argc, char* argv[])
{
    int nbGameObjects = 0, i = 0;
    int FPS = 60;
    int delayTime = (int)1000 / FPS;
    Uint32 nextTime, frameStart, nbFrames, frameTime;
    /** void* gameObjects; //malloc*/
    void* gameObjects[10];
    EnemyObject eo;
    stateVariables sv;

    atexit(clean);
    sv.fenetre = init(argc, argv, &sv);

    initEnemyObject(&eo);
    gameObjects[i++] = &eo;

    nbFrames = 0;
    nextTime = SDL_GetTicks() + TICK_INTERVAL;
    while (!sv.done) {
        ++nbFrames;
        frameStart = SDL_GetTicks();

        handleEvents(sv.fenetre, &sv);
        render(gameObjects, sv.fenetre);
        update(gameObjects, &sv);

        // capping frame rate. Doesn't seem to be working.
        /** frameTime = SDL_GetTicks() - frameStart; */
        /** if (frameTime < delayTime) { */
        /**     SDL_Delay((int)(delayTime - frameTime)); */
        /** } */

        // time based capping
        /** SDL_Delay(timeLeft(nextTime)); */
        /** nextTime += TICK_INTERVAL; */

        getFrameRate(frameStart, nbFrames);
    }

    SDL_FreeSurface(sv.fenetre);
    return 0;
}
