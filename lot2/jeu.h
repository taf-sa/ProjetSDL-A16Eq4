#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <SDL/SDL.h>
#include <stdbool.h>

typedef struct
{
    int debug_flip, numsprites;
    bool done, winResized;
    int winWidth, winHeight;
    Uint32 videoFlags;
    Uint8 video_bpp;
    SDL_Surface* fenetre;
} stateVariables;

void handleArguments(int argc, char* argv[], stateVariables* sv);
SDL_Surface* init(int argc, char* argv[], stateVariables* sv);
void initStateVariables(stateVariables* sv);
void clean();
Uint32 fastestFlags(Uint32 flags, int width, int height, int bpp);
void handleEvents(SDL_Surface* fenetre, stateVariables* sv);
void getFramerate(Uint32 then, Uint32 frames);
void update(void* gameObjects[], stateVariables* sv);
void render(void* gameObjects[], SDL_Surface* fenetre);

#endif
