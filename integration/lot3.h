#ifndef __LOT3_H
#define __LOT3_H
#include <SDL/SDL.h>

typedef struct
{
    SDL_Surface* miniature;
    SDL_Rect positionminimap;
    SDL_Surface* img;
    SDL_Rect camera;
    SDL_Rect posminiperso;

} minimap;

typedef struct
{
    SDL_Surface* miniperso;
    SDL_Rect positionminiperso;
    SDL_Surface* img;
    SDL_Rect camera;
    SDL_Rect posminiperso;

} miniperso;

void initminimap(minimap* m);
// void initminiperso(miniperso* m, perso p);
void afficherminimap(minimap m, SDL_Surface* screen);
// void MAJMinimapb(minimap* m, perso p);

void pause();
int gestion_score(int collision, int i);

SDL_Color GetPixel(SDL_Surface* background_mask, int x, int y);
int detectCollPP(SDL_Surface* BackgroundMasque, SDL_Rect Personnage);

#endif
