#include "ennemi.h"
#include "gameObjects.h"
#include "outils.h"
#include <SDL/SDL_timer.h>
#include <math.h>
#include <time.h>

#define nbAnimationFrames 23
#define animationRate 10

void initEnnemi(Ennemi* e)
{
    Uint16 width, height;
    e->image = chargerImage("ressources/sonic4.png");
    width = e->image->w / nbAnimationFrames;
    height = e->image->h;

    e->animFrame = (SDL_Rect){ .x = 0, .y = 0, .w = width, .h = height };
    e->pos = (SDL_Rect){ .x = 0, .y = 0, .w = width, .h = height };
    e->animStartTime = SDL_GetTicks();
    e->currentAnimFrameIndex = 0;
    e->direction = 0;
    e->etat = 0;
    e->isActive = true;
    e->xSpeed = 0.7;
    e->ySpeed = 0.0;
}

void afficherEnnemi(Ennemi e, SDL_Surface* fenetre)
{
    SDL_BlitSurface(e.image, &(e.animFrame), fenetre, &e.pos);
}

void animerEnnemi(Ennemi* e)
{
    int hold = (((SDL_GetTicks() - e->animStartTime) * animationRate / 1000) % nbAnimationFrames);
    e->animFrame.x = hold * e->animFrame.w;
}

void cleanEnnemi(Ennemi* e)
{
    SDL_FreeSurface(e->image);
}

void mettreAJourEnnemi(Ennemi* e, void** gameObjects, stateVariables sv)
{
    if (e->isActive) {
        int i = 0;
        EnemyObject* eo2;
        animerEnnemi(e);
        while (i < 10) {
            i++;
            eo2 = (EnemyObject*)gameObjects + i;
            if ((e->pos.x < 0) || (e->pos.x + e->pos.w > sv.fenetre->w) || (collisionBB(e->pos, eo2->e.pos))) {
                e->pos.x -= e->xSpeed;
            }

            if ((e->pos.y < 0) || (e->pos.y + e->pos.h > sv.fenetre->h) || (collisionBB(e->pos, eo2->e.pos))) {

                e->pos.y -= e->ySpeed;
            }
            deplacer(e);
        }
    }
}

int collisionBB(SDL_Rect posp, SDL_Rect pose)
{
    int top1, top2;
    int bottom1, bottom2;
    int rightSide1, rightSide2;
    int leftSide1, leftSide2;

    leftSide1 = posp.x;
    rightSide1 = posp.x + posp.w;
    top1 = posp.y;
    bottom1 = posp.y + posp.h;

    leftSide2 = pose.x;
    rightSide2 = pose.x + pose.w;
    top2 = pose.y;
    bottom2 = pose.y + pose.h;

    if (rightSide1 <= leftSide2)
        return 0;
    if (leftSide1 >= rightSide2)
        return 0;
    if (bottom1 <= top2)
        return 0;
    if (top1 >= bottom2)
        return 0;

    return 1;
}

void deplacer(Ennemi* e)
{
    e->pos.x += e->xSpeed;
    e->pos.y += e->ySpeed;
    /** e->pos.y = sinMovement(); */
}

int sinMovement()
{
    int y;
    int A = 50;
    int angle = 40;
    int phi = 0;
    Uint32 t = SDL_GetTicks();
    float frequency = (float)1 / 3;

    y = (int)A * sin(angle * 2 * 3.141 * frequency * t + phi);
    return y;
}

int randMov()
{

    time_t t;
    srand((unsigned)time(&t));
    return rand() % 50;
}

