#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <SDL/SDL.h>
#include <stdbool.h>

void handleArguments(int argc, char* argv[], int* width, int* height, Uint8* video_bpp, Uint32* videoflags, int* debug_flip, int* numsprites);
SDL_Surface* init(int w, int h, Uint8 video_bpp, Uint32 videoFlags, bool fullscreen);
void clean();
Uint32 fastestFlags(Uint32 flags, int width, int height, int bpp);
void handleEvents(int* done, SDL_Surface* fenetre, Uint8 video_bpp, Uint32 videoflags);
void getFramerate(Uint32 then, Uint32 frames);
void update(void* gameObjects[]);
void render(void* gameObjects[], SDL_Surface* fenetre);

#endif
