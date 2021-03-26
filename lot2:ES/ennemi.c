#include "ennemi.h"
#include "gameObjects.h"
#include "outils.h"

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
    e->didCollide = 0;
    e->isActive = true;
    e->xSpeed = 0;
    e->ySpeed = 0;
}

void afficherEnnemi(Ennemi e, SDL_Surface* fenetre)
{
    SDL_FillRect(fenetre, &e.pos, SDL_MapRGB(e.image->format, 0, 0, 0));
    /** SDL_UpdateRect(fenetre, 0, 0, 0, 0); */
    SDL_BlitSurface(e.image, &(e.animFrame), fenetre, &e.pos);
}

void animerEnnemi(Ennemi* e)
{
    int hold = (((SDL_GetTicks() - e->animStartTime) * animationRate / 1000) % nbAnimationFrames);
    // TODO animation frame rate depends on game loop frequency set timer? SDL_SetTimer()?
    /** if (e->currentAnimFrame == 23) */
    /**     e->currentAnimFrame = 0; */
    /** e->animFrame.x = (++(e->currentAnimFrame)) * (e->animFrame.w); */

    e->animFrame.x = hold * e->animFrame.w;
}

void mettreAJourEnnemi(void* gameObjects, stateVariables sv)
{
    int i = 0;
    EnemyObject *eo, *eo2;
    eo = (EnemyObject*)gameObjects + i;
    animerEnnemi(&eo->e);
    while (i < 10) {
        i++;
        eo2 = (EnemyObject*)gameObjects + i;
        if (eo->e.isActive) {
            if ((eo->e.pos.x < 0) || (eo->e.pos.x + eo->e.pos.w > sv.fenetre->w) || (collisionBB(eo->e.pos, eo2->e.pos))) {
                eo->e.pos.x -= eo->e.xSpeed;
            }

            if ((eo->e.pos.y < 0) || (eo->e.pos.y + eo->e.pos.h > sv.fenetre->h) || (collisionBB(eo->e.pos, eo2->e.pos))) {

                eo->e.pos.y -= eo->e.ySpeed;
            }
            deplacer(&eo->e);
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
}

