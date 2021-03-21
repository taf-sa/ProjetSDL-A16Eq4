#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <SDL/SDL.h>
#include <stdbool.h>

SDL_Surface* init(int w, int h, Uint8 video_bpp, Uint32 videoFlags, bool fullscreen);
void clean();

Uint32 fastestFlags(Uint32 flags, int width, int height, int bpp);
#endif
