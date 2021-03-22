#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include <SDL/SDL.h>

typedef struct
{
    SDL_Surface* image;
    SDL_Rect pos;
    SDL_Rect animFrame;
    int direction;
    int etat;
    int collision;
    int currentFrame;
    // void (*draw)(SDL_Surface*);
    // void (*miseAJour)();
} Ennemi;

void initEnnemi(Ennemi* e);
void afficherEnnemi(Ennemi e, SDL_Surface* fenetre);
void animerEnnemi(Ennemi* e);
void deplacer(Ennemi* e);
int collisionBB(SDL_Rect posp, SDL_Rect pose);
void deplacerIA(Ennemi* e);

SDL_Surface* chargerImage(char* nomImage);
SDL_Surface* chargerImageBMP(char* nomImage);
#endif
