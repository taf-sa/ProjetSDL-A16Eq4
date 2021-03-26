#include "ennemi.h"
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
    e->collision = 0;
}

void afficherEnnemi(Ennemi e, SDL_Surface* fenetre)
{
    SDL_FillRect(fenetre, &e.pos, SDL_MapRGB(e.image->format, 0, 0, 0));
    /** SDL_UpdateRect(fenetre, 0, 0, 0, 0); */
    SDL_BlitSurface(e.image, &(e.animFrame), fenetre, &e.pos);
}

void animerEnnemi(Ennemi* e)
{
    int hold;

    hold = (((SDL_GetTicks() - e->animStartTime) * animationRate / 1000) % nbAnimationFrames);
    // TODO animation frame rate depends on game loop frequency set timer? SDL_SetTimer()?
    /** if (e->currentAnimFrame == 23) */
    /**     e->currentAnimFrame = 0; */
    /** e->animFrame.x = (++(e->currentAnimFrame)) * (e->animFrame.w); */

    e->animFrame.x = hold * e->animFrame.w;
}

void mettreAJourEnnemi(Ennemi* e, SDL_Surface* fenetre)
{
    animerEnnemi(e);
}

