#include "ennemi.h"
#include "jeu.h"
#include <SDL/SDL.h>

int main(int argc, char* argv[])
{
    SDL_Surface* fenetre;
    Ennemi e;

    fenetre = init(300, 400, false);
    initEnnemi(&e);
    afficherEnnemi(e, fenetre);
    SDL_Delay(2000);

    return 0;
}
