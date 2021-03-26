#ifndef ENNEMI_H
#define ENNEMI_H
#include <SDL/SDL_image.h>

typedef struct
{
    SDL_Surface* image;
    SDL_Rect pos;
    SDL_Rect animFrame;
    Uint32 animStartTime;
    int currentAnimFrameIndex;
    int direction;
    int etat;
    int collision;
} Ennemi;

void initEnnemi(Ennemi* e);
void afficherEnnemi(Ennemi e, SDL_Surface* fenetre);
void animerEnnemi(Ennemi* e);
void deplacer(Ennemi* e);
int collisionBB(SDL_Rect posp, SDL_Rect pose);
void deplacerIA(Ennemi* e);

void mettreAJourEnnemi(Ennemi* e, SDL_Surface* fenetre);
#endif
