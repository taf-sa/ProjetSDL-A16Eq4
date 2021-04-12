#include "SDL/SDL.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enigm.h"
#include <math.h>

#include "SDL/SDL_ttf.h"

int main(void)
{
    SDL_Surface* screen;
    screen = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    screen = SDL_SetVideoMode(564, 772, 24, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("enigmes sans fichier", NULL);

    int n = 0, f = 0, e = 0, k = 0;
    f = rand() % 10;
    k = rand() % 10;
    e = rand() % 10;
    n = rand() % 10;
    int aziz, r;

    n = generate_question(&n);

    init_affichier_question(n, screen);
    aziz = resolution(n, e, k, f);
    printf("Aziz: %d\n", aziz);

    r = reponse(&r);
    printf("%d %d", r, aziz);
    afficher_resultat(screen, aziz, r);
    SDL_Quit();
    return 0;
}
