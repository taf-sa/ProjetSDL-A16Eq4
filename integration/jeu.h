#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include "background.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdbool.h>

typedef struct
{
    int debug_flip, numsprites;
    int winWidth, winHeight;
    int volume;
    bool done, winResized;
    background bg;
    Uint32 videoFlags;
    Uint8 video_bpp;
    Mix_Music* musique;
    SDL_Surface* fenetre;
    SDL_Surface* icon;
} stateVariables;

void handleArguments(int argc, char* argv[], stateVariables* sv);
SDL_Surface* init(int argc, char* argv[], stateVariables* sv);
void initStateVariables(stateVariables* sv);
void clean();
void freeSurfaces(stateVariables* sv);
Uint32 fastestFlags(Uint32 flags, int width, int height, int bpp);
void handleEvents(stateVariables* sv);
void getFrameRate(Uint32 then, Uint32 frames);
void update(void* gameObjects[], stateVariables* sv);
void render(void* gameObjects[], SDL_Surface* fenetre);
Uint32 timeLeft(Uint32 nextTime);

#endif
