#ifndef GAMEOBJECTS_H_INCLUDED
#define GAMEOBJECTS_H_INCLUDED

#include "ennemi.h"

typedef struct
{
    Ennemi e;
    void (*miseAJour)(Ennemi*, SDL_Surface*);
    void (*draw)(Ennemi, SDL_Surface*);

} EnemyObject;

void initEnemyObject(EnemyObject* eo);
#endif
