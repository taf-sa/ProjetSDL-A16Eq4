#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"




int main(int argc, char *argv[])
{

 background b;
 SDL_Surface* screen  = NULL;
 int continuer=1;
 SDL_Event event;

 SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
 screen=SDL_SetVideoMode(1680,1050,32,SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN); // Ouverture de la fenêtre
 if(!screen)
  {
    printf("unable to set 1400x1050 video: %s\n",SDL_GetError());
    return (-1);
  }
 SDL_WM_SetCaption("background ahmed", NULL);

 initialiser_background(&b);
 
while(continuer)
    {

	afficher_background(b,screen);
        
  
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break; 

            case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                             continuer = 0;
                             break;
                        default:
                             break;
                    }
         
             }
        
        }
        SDL_Flip(screen);
        
    }
SDL_Quit(); // Arrêt de la SDL
return EXIT_SUCCESS; // Fermeture du programme
}
