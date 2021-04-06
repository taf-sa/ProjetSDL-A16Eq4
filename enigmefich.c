#include <stdio.h>
#include <stdlib.h>
#include "enigmefich.h"

void genererEnigme(enigme * e,char *nomfichier)
{
  FILE* fichier;
 fichier=fopen("nomfichier","r");
 if(fichier!=NULL)
 {
     
     fclose(fichier);
 }
}
void afficherEnigme(enigme e, SDL_Surface * screen)
{
 FILE* fichier;
 fichier=fopen("nomfichier","r");
 if(fichier!=NULL)
 {
     genererEnigme(&e,&nomfichier);
     fclose(fichier);
 }
}
void sauvegarder (personne p, background b, char* nomfichier)
{

}
