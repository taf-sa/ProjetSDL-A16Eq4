#include "ennemi.h"
#include "outils.h"

#define nbAnimationFrames 23

void initEnnemi(Ennemi* e)
{
    Uint16 width, height;
    e->image = chargerImage("ressources/sonic4.png");
    width = e->image->w / nbAnimationFrames; // sprite has 23 frames of animation in in each line
    height = e->image->h;

    e->animFrame = (SDL_Rect){ .x = 0, .y = 0, .w = width, .h = height };
    e->pos = (SDL_Rect){ .x = 0, .y = 0, .w = width, .h = height };
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
    int currentFrame = 1;
    currentFrame = (int)(((SDL_GetTicks() / 100) % nbAnimationFrames)) + 1;
    /** e->animFrame.x = ((e->animFrame.x + e->animFrame.w) % e->image->w) + 1; */
    /** SDL_Delay(100); */
    e->animFrame.x = currentFrame * (e->animFrame.w); // TODO skips frames
}

void mettreAJourEnnemi(Ennemi* e, SDL_Surface* fenetre)
{
    animerEnnemi(e);
    // Debuging
    /** e->pos.x += e->animFrame.w; */
    /** if ((e->pos.x + e->animFrame.w) >= fenetre->w) { */
    /**     e->pos.x = 0; */
    /**     e->pos.y += e->animFrame.h; */
    /** } */
    /** SDL_Delay(700); */
}
