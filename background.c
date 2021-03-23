#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"
void initialiser_background(background *b)
{
	b->calque_background=NULL;
	b->calque_background=IMG_Load("calquebackground.png");

	b->afficher_background=NULL;
	b->afficher_background=IMG_Load("background.jpg");
	b->pos_background.x=0;
	b->pos_background.y=0;
	b->pos_background2.x=0;
	b->pos_background2.y=0;
	b->pos_background2.h=600;
	b->pos_background2.w=1200;
}
void afficher_background(background b,SDL_Surface *screen)
{
	SDL_BlitSurface(b.afficher_background,&(b.pos_background2),screen,&(b.pos_background));
	SDL_Flip(screen);
}
