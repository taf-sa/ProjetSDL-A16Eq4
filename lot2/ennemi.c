#include "ennemi.h"

void initEnnemi(Ennemi* e)
{
    Uint16 width, height;
    e->image = chargerImage("ressources/sonic.png");
    width = e->image->w / 10; // sprite has 7 frames of animation in in each line
    height = e->image->h / 3; // sprite has 3 lines

    e->animFrame = (SDL_Rect){ .x = 0, .y = 0, .w = width, .h = height };
    e->pos = (SDL_Rect){ .x = 0, .y = 0, .w = width, .h = height };
    e->direction = 0;
    e->etat = 0;
    e->collision = 0;
}

void afficherEnnemi(Ennemi e, SDL_Surface* fenetre)
{
    SDL_FillRect(fenetre, &e.pos, SDL_MapRGB(e.image->format, 0, 0, 0));
    /** SDL_UpdateRect(fenetre, 0, 0, 0, 0); */
    SDL_BlitSurface(e.image, &(e.animFrame), fenetre, &e.pos);
}

void animerEnnemi(Ennemi* e)
{
    int currentFrame = 1;
    currentFrame = (int)(((SDL_GetTicks() / 100) % 9)) + 1;
    /** e->animFrame.x = ((e->animFrame.x + e->animFrame.w) % e->image->w) + 1; */
    /** SDL_Delay(100); */
    e->animFrame.x = currentFrame * (e->animFrame.w); // TODO skips frames
}

void mettreAJourEnnemi(Ennemi* e, SDL_Surface* fenetre)
{
    animerEnnemi(e);
    // Debuging
    /** e->pos.x += e->animFrame.w; */
    /** if ((e->pos.x + e->animFrame.w) >= fenetre->w) { */
    /**     e->pos.x = 0; */
    /**     e->pos.y += e->animFrame.h; */
    /** } */
    /** SDL_Delay(700); */
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
