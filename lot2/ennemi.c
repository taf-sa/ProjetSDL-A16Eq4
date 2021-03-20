#include "ennemi.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_video.h>

void initEnnemi(Ennemi* e)
{
    e->image = chargerImage("ressources/sonic.png");
    e->pos = (SDL_Rect){ .x = 0, .y = 0, .w = 100, .h = 200 };
    e->direction = 0;
    e->etat = bien;
    e->collision = 0;
}

void afficherEnnemi(Ennemi e, SDL_Surface* fenetre)
{
    SDL_BlitSurface(e.image, &(e.pos), fenetre, NULL);
    SDL_Flip(fenetre);
}

SDL_Surface* chargerImage(char* nomImage)
{
    SDL_Surface* image;

    image = IMG_Load(nomImage);
    if (!image) {
        printf("Failed to load \"%s\"\n", nomImage);
        printf("IMG_Load: %s\n", IMG_GetError());
    }

    return image;
}
