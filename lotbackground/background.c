#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"background.h"
void initialiser_background(background *b)
{
	
	b->afficher_background=NULL;
	b->afficher_background=IMG_Load("background.jpg");
        b->pos.x=0;
        b->pos.y=0;
	b->pos_background.x=0;
	b->pos_background.y=0;
	b->pos_background.h=b->afficher_background->h;
	b->pos_background.w=b->afficher_background->w*0.25;
}
void afficher_background(background b,SDL_Surface *screen)
{
	SDL_BlitSurface(b.afficher_background,&(b.pos_background),screen,&(b.pos));
	SDL_Flip(screen);
}

void scrolling(background *b,int direction)
{
  if ((direction>0)&&(b->pos_background.w - b->pos_background.x != CAMERA_W))
     {
       b->pos_background.x+=5;
     }
  else 
    if ((direction<0)&&(b->pos_background.x != 0))
     {
       b->pos_background.x=b->pos_background.x-5;
     }
}
