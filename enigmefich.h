#ifndef ENIGMEFICH_H_INCLUDED
#define ENIGMEFICH_H_INCLUDED

typedef struct
{
  char question[30];
  char reponse1[20];
  char reponse2[20];
  char reponse3[20];
  int reponsejuste;
}enigme;
typedef struct
{

}personne;
typedef struct
{

}background;

void afficherEnigme(enigme e, SDL_Surface * screen);
void genererEnigme(enigme * e,char *nomfichier);
void sauvegarder (personne p, background b, char* nomfichier);
#endif // ENIGMEFICH_H_INCLUDED
