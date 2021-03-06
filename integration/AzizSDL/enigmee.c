#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "enigm.h"
#include "time.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int generate_question(int* n)
{
    int a;
    srand(time(NULL));
    *n = 1 + rand() % 10;
    a = (*n);
    return a;
}

void init_affichier_question(int n, SDL_Surface* screen)
{
    char question[100];
    char question1[100];
    char question2[100];
    int e, f, k;
    f = rand() % 10;
    k = rand() % 10;
    e = rand() % 10;

    sprintf(question, "on se pose que n= %d", n);
    sprintf(question1, "aziz=(( %d * %d )+%d ) * %d ", f, k, n, e);
    sprintf(question2, "aziz??");
    SDL_Surface* background = NULL;
    SDL_Surface* message = NULL;
    SDL_Surface* message1 = NULL;
    SDL_Surface* message2 = NULL;
    //La structure d'événement

    //Le Font qu'on va utiliser
    TTF_Font* font = NULL;

    //La couleur du Font
    SDL_Color textColor = { 255, 0, 0 };

    //Initialisation de SDL_TTF
    if (TTF_Init() == -1) {
        printf("false");
    }

    //Mise en place de la barre caption

    background = IMG_Load("ressources/background.jpg");
    font = TTF_OpenFont("ressources/caslon.ttf", 28);
    //Mise en place du texte sur la surface message
    message = TTF_RenderText_Solid(font, question, textColor);
    message1 = TTF_RenderText_Solid(font, question1, textColor);
    message2 = TTF_RenderText_Solid(font, question2, textColor);
    //Application des images sur l'écran

    SDL_Rect p;
    p.x = 150;
    p.y = 306;
    SDL_Rect p1;
    p1.x = 150;
    p1.y = 366;
    SDL_Rect p2;
    p2.x = 250;
    p2.y = 426;
    SDL_BlitSurface(background, NULL, screen, NULL);
    SDL_BlitSurface(message, NULL, screen, &p);
    SDL_BlitSurface(message1, NULL, screen, &p1);
    SDL_BlitSurface(message2, NULL, screen, &p2);
    SDL_Flip(screen);

    //Fermeture des Fonts qu'on a utilisé
    TTF_CloseFont(font);

    //On quitte SDL_ttf
    TTF_Quit();
}

int resolution(int n, int f, int e, int k)
{
    int aziz;
    aziz = ((f * k) + n) * e;
    return aziz;
}

int reponse(int* rep)
{
    int i, r, y, z, coff;
    (*rep) = 0;
    SDL_Event event;
    int continuer = 1;

    while (continuer) {
        SDL_WaitEvent(&event);
        switch (event.type) {
        case SDL_QUIT:
            continuer = 0;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_KP1:
                r = 1;
                (*rep) = (r * 100);
                continuer = 0;
                break;
            case SDLK_KP2:
                r = 2;
                (*rep) = (r * 100);
                continuer = 0;
                break;
            case SDLK_KP3:
                r = 3;
                (*rep) = (r * 100);
                continuer = 0;
                break;

            case SDLK_KP4:
                r = 4;
                (*rep) = (r * 100);
                continuer = 0;
                break;
            case SDLK_KP5:
                r = 5;
                (*rep) = (r * 100);
                continuer = 0;
                break;
            case SDLK_KP6:
                r = 6;
                (*rep) = (r * 100);
                continuer = 0;
                break;
            case SDLK_KP7:
                r = 7;
                (*rep) = (r * 100);
                continuer = 0;
                break;
            case SDLK_KP8:
                r = 8;
                (*rep) = (r * 100);
                continuer = 0;
                break;
            case SDLK_KP9:
                r = 9;
                (*rep) = (r * 100);
                continuer = 0;
                break;
            case SDLK_KP0:
                r = 0;
                (*rep) = (*rep) + (r * 100);
                continuer = 0;
                break;
            }
            break;
        }
    }
    continuer = 1;

    /*second int*/
    while (continuer) {
        SDL_WaitEvent(&event);
        switch (event.type) {
        case SDL_QUIT:
            continuer = 0;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_KP1:
                y = 1;
                (*rep) = (*rep) + (y * 10);
                continuer = 0;
                break;
            case SDLK_KP2:
                y = 2;
                (*rep) = (*rep) + (y * 10);
                continuer = 0;
                break;
            case SDLK_KP3:
                y = 3;
                (*rep) = (*rep) + (y * 10);
                continuer = 0;
                break;

            case SDLK_KP4:
                y = 4;
                (*rep) = (*rep) + (y * 10);
                continuer = 0;
                break;
            case SDLK_KP5:
                y = 5;
                (*rep) = (*rep) + (y * 10);
                continuer = 0;
                break;
            case SDLK_KP6:
                y = 6;
                (*rep) = (*rep) + (y * 10);
                continuer = 0;
                break;
            case SDLK_KP7:
                y = 7;
                (*rep) = (*rep) + (y * 10);
                continuer = 0;
                break;
            case SDLK_KP8:
                y = 8;
                (*rep) = (*rep) + (y * 10);
                continuer = 0;
                break;
            case SDLK_KP9:
                y = 9;
                (*rep) = (*rep) + (y * 10);
                continuer = 0;
                break;
            case SDLK_KP0:
                y = 0;
                (*rep) = (*rep) + (y * 10);
                continuer = 0;
                break;
            }
            break;
        }
    }
    continuer = 1;

    /*third int*/
    while (continuer) {
        SDL_WaitEvent(&event);
        switch (event.type) {
        case SDL_QUIT:
            continuer = 0;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_KP1:
                z = 1;
                (*rep) = (*rep) + z;
                continuer = 0;
                break;
            case SDLK_KP2:
                z = 2;
                (*rep) = (*rep) + z;
                continuer = 0;
                break;
            case SDLK_KP3:
                z = 3;
                (*rep) = (*rep) + z;
                continuer = 0;
                break;

            case SDLK_KP4:
                z = 4;
                (*rep) = (*rep) + z;
                continuer = 0;
                break;
            case SDLK_KP5:
                z = 5;
                (*rep) = (*rep) + z;
                continuer = 0;
                break;
            case SDLK_KP6:
                z = 6;
                (*rep) = (*rep) + z;
                continuer = 0;
                break;
            case SDLK_KP7:
                z = 7;
                (*rep) = (*rep) + z;
                continuer = 0;
                break;
            case SDLK_KP8:
                z = 8;
                (*rep) = (*rep) + z;
                continuer = 0;
                break;
            case SDLK_KP9:
                z = 9;
                (*rep) = (*rep) + z;
                continuer = 0;
                break;
            case SDLK_KP0:
                z = 0;
                (*rep) = (*rep) + z;
                continuer = 0;
                break;
            }
            break;
        }
    }

    int b;
    b = (*rep);
    return b;
}

void afficher_resultat(SDL_Surface* screen, int aziz, int r)
{
    SDL_Surface* background;
    background = NULL;
    int solution = aziz;

    if (r == solution) {
        background = IMG_Load("ressources/pass.jpg");
        SDL_BlitSurface(background, NULL, screen, NULL);
        SDL_Flip(screen);
        SDL_Delay(3000);
    } else {
        background = IMG_Load("ressources/failed.jpg");
        SDL_BlitSurface(background, NULL, screen, NULL);
        SDL_Flip(screen);
        SDL_Delay(3000);
    }
}
