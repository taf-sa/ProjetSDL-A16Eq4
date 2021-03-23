
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <unistd.h>

typedef struct background
   {
	SDL_Surface *afficher_background;
	SDL_Rect pos_background;
	SDL_Rect pos_background2;
	SDL_Surface *calque_background;
        SDL_Rect position;
   }background;

void initialiser_background(background *b);
void afficher_background(background b,SDL_Surface *screen);


#endif
