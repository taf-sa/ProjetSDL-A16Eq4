#ifndef __BACKGROUND_H
#define __BACKGROUND_H

#include <SDL/SDL.h>

#define CAMERA_W 400
#define CAMERA_H 700

typedef struct background {
    SDL_Surface* afficher_background;
    SDL_Rect pos_background;
    SDL_Rect pos;

} background;

void initialiser_background(background* b);
void afficher_background(background b, SDL_Surface* screen);
void scrolling(background* b, int direction);

#endif
