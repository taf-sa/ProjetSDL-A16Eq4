#include "gameObjects.h"

void initEnemyObject(EnemyObject* eo)
{
    Ennemi e;
    initEnnemi(&e);
    eo->e = e;
    eo->afficherEnnemi = afficherEnnemi;
    eo->animerEnnemi = animerEnnemi;
}
