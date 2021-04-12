#ifndef OUTILS_H
#define OUTILS_H
#include <SDL/SDL_image.h>
#include <stdbool.h>

typedef struct timer Timer;
struct timer {
    bool isStarted;
    bool isPaused;
    Uint32 startTime;
    Uint32 pausedTime;
};

SDL_Surface* chargerImage(char* nomImage);
SDL_Surface* chargerImageBMP(char* nomImage);

Timer initTimer();
void startTimer(Timer*);
void stopTimer(Timer*);
void pauseTimer(Timer*);
void continueTimer(Timer*);
Uint32 getTime(Timer t);

Uint32 getpixel(SDL_Surface* surface, int x, int y); // from the SDL documentation
Uint32 timeLeft(Uint32 nextTime);

#endif

