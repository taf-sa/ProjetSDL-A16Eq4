#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "time.h"
#include "SDL/SDL.h"
#include <math.h>
#include <SDL/SDL_image.h>
int generate_question(int*n);
void init_affichier_question(int n,SDL_Surface *screen);
int resolution(int n,int f,int e, int k);
int reponse(int *rep );
void afficher_resultat (SDL_Surface * screen,int aziz,int r);
