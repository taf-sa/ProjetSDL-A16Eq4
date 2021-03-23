#include "gameObjects.h"

void initEnemyObject(EnemyObject* eo)
{
    Ennemi e;
    initEnnemi(&e);
    eo->e = e;
    eo->miseAJour = mettreAJourEnnemi;
    eo->draw = afficherEnnemi;
}
