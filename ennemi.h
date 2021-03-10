#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <SDL/SDL.h>

// version initiale
typedef struct
{
	SDL_Surface *image;
	SDL_Rect flipbook[3][8]; // sprite
	SDL_Rect pose;
	int direction;
	int animation;
	int distance;
	int etat;
	int collision;
} Ennemi;

void initEnnemi(Ennemi *e);
void afficherEnnemi(Ennemi e, SDL_Surface *fenetre);
void animerEnnemi(Ennemi *e);
void deplacer(Ennemi *e);
int collisionBB(SDL_Rect posp, SDL_Rect pose);
void deplacerIA(Ennemi *e);

#endif
