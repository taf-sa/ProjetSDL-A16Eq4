#ifndef GAMEOBJECTS_H_INCLUDED
#define GAMEOBJECTS_H_INCLUDED

#include "ennemi.h"
#include "jeu.h"

typedef struct
{
    Ennemi e;
    void (*miseAJour)(void*, stateVariables);
    void (*draw)(Ennemi, SDL_Surface*);

} EnemyObject;

void initEnemyObject(EnemyObject* eo);
#endif
