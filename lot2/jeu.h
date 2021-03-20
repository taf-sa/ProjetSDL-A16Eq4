#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <SDL/SDL.h>
#include <stdbool.h>

SDL_Surface* init(int w, int h, bool fullscreen);
void clean();
#endif
