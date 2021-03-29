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
 int d,continuer=1;
 SDL_Event event;
 Mix_Music *musique; //Création d'un pointeur de type Mix_Music
 int volume;
 

 if(SDL_Init(SDL_INIT_VIDEO) == -1) // Initialisation de la SDL
  {
    printf("failure init_SDL : %s \n",SDL_GetError ());
    return EXIT_FAILURE;
  }
 screen=SDL_SetVideoMode(CAMERA_W,CAMERA_H,32,SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN); // Ouverture de la fenêtre
 if(!screen)
  {
    printf("unable to set 1400x1050 video: %s\n",SDL_GetError());
    return (-1);
  }
 SDL_WM_SetCaption("background ahmed", NULL);

 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
  volume=MIX_MAX_VOLUME / 4;
  Mix_VolumeMusic(volume); 
  musique = Mix_LoadMUS("music.mp3"); //Chargement de la musique
  Mix_PlayMusic(musique, -1); //Jouer infiniment la musique

 initialiser_background(&b);
 SDL_EnableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);


while(continuer)
    {

	
        
  
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
                        case SDLK_LEFT:
                             d=-1;
                             scrolling(&b,d);
                             if (volume>0)
                               {
                                 volume--;
                               }
                               Mix_VolumeMusic(volume);
                             break;
                        case SDLK_RIGHT:
                             d=1;
                             scrolling(&b,d);
                             if (volume<128)
                               {
                                 volume++;
                               }
                               Mix_VolumeMusic(volume);
                             break;
                        case SDLK_UP:
                             d=-2;
                             scrolling(&b,d);
                             break;
                        case SDLK_DOWN:
                             d=2;
                             scrolling(&b,d);
                             break;
                        default:
                             break;
                    }
                    break;
         
             }
        
        }
        afficher_background(b,screen);
        SDL_Flip(screen);
        
    }
Mix_CloseAudio(); //Fermeture de l'API
SDL_FreeSurface(screen);
SDL_FreeSurface(b.afficher_background);
SDL_Quit(); // Arrêt de la SDL
return EXIT_SUCCESS; // Fermeture du programme
}
