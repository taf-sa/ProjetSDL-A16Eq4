#ifndef GAMEOBJECTS_H_INCLUDED
#define GAMEOBJECTS_H_INCLUDED

#include "ennemi.h"
#include "jeu.h"

typedef struct enemy EnemyObject;
typedef struct enemy Personne;
struct enemy {
    Ennemi e;
    void (*miseAJour)(Ennemi*, void**, stateVariables);
    void (*draw)(Ennemi, SDL_Surface*);
    void (*clean)(Ennemi*);
};

void initEnemyObject(EnemyObject* eo);
#endif
