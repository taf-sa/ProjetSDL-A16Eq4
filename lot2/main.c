#include "gameObjects.h"
#include "jeu.h"
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int nbGameObjects = 0;
    /** int* gameObjects; // array of all game objects */
    /** Ennemi* EnnemiOjbjects; // array of enemies */
    void* gameObjects[10];
    Ennemi ennemis[10];
    EnemyObject eo;
    int i = 0;
    Uint32 then, frames;
    stateVariables sv;
    Ennemi e;

    atexit(clean);
    sv.fenetre = init(argc, argv, &sv);

    /** initEnnemi(&e); */
    initEnemyObject(&eo, &e);
    gameObjects[i++] = &eo;

    Uint32 color = SDL_MapRGB(eo.e->image->format, 0, 0, 0);
    frames = 0;
    //afficherEnnemi(e, fenetre);

    while (!sv.done) {
        ++frames;
        then = SDL_GetTicks();
        handleEvents(sv.fenetre, &sv);
        /** afficherEnnemi(e, sv.fenetre); */
        update(gameObjects, &sv);
        /** render(gameObjects, sv.fenetre); */
        //animerEnnemi(&e);
        SDL_FillRect(sv.fenetre, NULL, color);
        //afficherEnnemi(e, fenetre);
        getFramerate(then, frames);
        /** SDL_Delay(100); */
    }

    SDL_FreeSurface(sv.fenetre);
    return 0;
}
