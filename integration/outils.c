#include "outils.h"

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

Timer initTimer()
{
    Timer t;
    t.startTime = 0;
    t.pausedTime = 0;
    t.isPaused = false;
    t.isStarted = false;
    return t;
}

void startTimer(Timer* t)
{
    t->isStarted = true;
    t->isPaused = false;
    t->startTime = SDL_GetTicks();
    t->pausedTime = 0;
}

void stopTimer(Timer* t)
{
    t->isStarted = false;
    t->isPaused = false;
    t->startTime = 0;
    t->pausedTime = 0;
}

void pauseTimer(Timer* t)
{
    if (t->isStarted && !t->isPaused) {
        t->isPaused = true;

        t->pausedTime = SDL_GetTicks() - t->startTime;
        t->startTime = 0;
    }
}

void continueTimer(Timer* t)
{
    if (t->isStarted && t->isPaused) {
        t->isPaused = false;
        t->startTime = SDL_GetTicks() - t->pausedTime;
        t->pausedTime = 0;
    }
}

Uint32 getTime(Timer t)
{
    Uint32 time = 0;

    if (t.isStarted) {
        if (t.isPaused) {
            time = t.pausedTime;
        } else {
            time = SDL_GetTicks() - t.startTime;
        }
    }

    return time;
}

// from the documentation of SDL
Uint32 getpixel(SDL_Surface* surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16*)p;

    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32*)p;

    default:
        return 0; /* shouldn't happen, but avoids warnings */
    }
}

Uint32 timeLeft(Uint32 nextTime)
{
    Uint32 now;

    now = SDL_GetTicks();
    if (nextTime <= now)
        return 0;
    else
        return nextTime - now;
}
