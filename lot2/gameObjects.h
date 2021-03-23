#ifndef GAMEOBJECTS_H_INCLUDED
#define GAMEOBJECTS_H_INCLUDED

#include "ennemi.h"
#include <SDL/SDL.h>

typedef struct
{
    Ennemi e;
    void (*afficherEnnemi)(Ennemi, SDL_Surface*);
    void (*animerEnnemi)(Ennemi*);

} EnemyObject;

void initEnemyObject(EnemyObject* eo);
#endif
