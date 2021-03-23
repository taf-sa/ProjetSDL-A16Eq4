#include "ennemi.h"

void initEnnemi(Ennemi* e)
{
    int width, height;
    e->image = chargerImage("ressources/sonic.png");
    width = (int)e->image->w / 10;
    height = (int)e->image->h / 3;

    e->pos = (SDL_Rect){ .x = 0, .y = 0 };
    /** e->animFrame = (SDL_Rect){ .x = (Sint16)width, .y = 0, .w = (Uint16)width, .h = (Uint16)height }; */
    e->animFrame = (SDL_Rect){ .x = 0, .y = 0, .w = (Uint16)width, .h = (Uint16)height };
    e->direction = 0;
    e->etat = 0;
    e->collision = 0;
}

void afficherEnnemi(Ennemi e, SDL_Surface* fenetre)
{
    SDL_BlitSurface(e.image, &(e.animFrame), fenetre, NULL);
    SDL_Flip(fenetre);
}

void animerEnnemi(Ennemi* e)
{
    int width, height, currentFrame;

    width = (int)e->image->w / 10;
    height = (int)e->image->h / 3;
    currentFrame = (int)(((SDL_GetTicks() / 100) % 9)) + 1;
    /** printf("frame %d\n", currentFrame); */
    /** e->animFrame.x = (e->animFrame.x + width) % e->image->w; */
    e->animFrame.x = currentFrame * width;
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

SDL_Surface* chargerImageBMP(char* nomImage)
{
    SDL_Surface *temp, *sprite;

    /* Load the sprite image */
    sprite = SDL_LoadBMP(nomImage);
    if (sprite == NULL) {
        fprintf(stderr, "Couldn't load %s: %s", nomImage, SDL_GetError());
        exit(1);
    }

    /* Set transparent pixel as the pixel at (0,0) */
    if (sprite->format->palette) {
        SDL_SetColorKey(sprite, (SDL_SRCCOLORKEY | SDL_RLEACCEL),
            *(Uint8*)sprite->pixels);
    }

    /* Convert sprite to video format */
    temp = SDL_DisplayFormat(sprite);
    SDL_FreeSurface(sprite);
    if (temp == NULL) {
        fprintf(stderr, "Couldn't convert background: %s\n",
            SDL_GetError());
        exit(1);
    }
    sprite = temp;
    return sprite;
}
