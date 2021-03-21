#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include <SDL/SDL.h>

enum etats { bien,
    pasBien };

typedef struct
{
    SDL_Surface* image;
    SDL_Surface* animation[3][8];
    SDL_Rect pos;
    int direction;
    int animations;
    int distance;
    enum etats etat;
    int collision;
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
