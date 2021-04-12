/** #include "lot3.h" */
/** #include <SDL/SDL_image.h> */
/**  */
/** void initminimap(minimap* m, perso p) */
/** { */
/**     m->positionminimap.x = 0; */
/**     m->positionminimap.y = 20; */
/**     m->miniature = IMG_Load("minimap/1.png"); */
/**  */
/**     //rajouter init imgminiperso perso+posminiperso */
/** }; */
/** void initminiperso(miniperso* m, perso p) */
/** { */
/**     m->positionminiperso.x = 0; */
/**     m->positionminiperso.y = 50; */
/**     m->miniperso = IMG_Load("miniperso.png"); */
/** }; */
/** void afficherminimap(minimap m, SDL_Surface* screen) */
/** { */
/**     SDL_BlitSurface(m->miniature, NULL, screen, &m->positionminimap); */
/**  */
/**     SDL_BlitSurface(m->miniperso, NULL, screen, &m->positionminiperso); */
/** } */
/**  */
/** void MAJMinimapb(minimap* m, perso p); */
/** { */
/**     SDL_RECT posA; */
/**     posA.x = p->posperso.x + b->camera.x; */
/**     posA.y = p->posperso.y + b->camera.y; */
/**     posminiperso.x = posA.x * 0.3; */
/**     posminiperso.y = posA.y * 0.3; */
/** } */
/**  */
/** void pause() */
/** { */
/**     int continuer = 1; */
/**     SDL_Event event; */
/**  */
/**     while (continuer) { */
/**         SDL_WaitEvent(&event); */
/**         switch (event.type) { */
/**         case SDL_QUIT: */
/**             continuer = 0; */
/**         } */
/**     } */
/** } */
/** int gestion_score(int collision, int i) */
/** { */
/**     SDL_Surface *ecran = NULL, *score = NULL; */
/**     SDL_Rect positionscore; */
/**     SDL_Rect rects[10]; */
/**     positionscore.x = 0; */
/**     positionscore.y = 0; */
/**     SDL_Init(SDL_INIT_VIDEO); */
/**  */
/**     ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE); */
/**     if (collision == 1) { */
/**         i++; */
/**         if (i > 10) { */
/**             i = 10; */
/**         } */
/**     } else if (collision == 0) { */
/**         i--; */
/**         if (i < 0) { */
/**             i = 0; */
/**         } */
/**     } */
/**     switch (i) { */
/**     case 0: */
/**         score = IMG_Load("0.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     case 1: */
/**         score = IMG_Load("1.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     case 2: */
/**         score = IMG_Load("2.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     case 3: */
/**         score = IMG_Load("3.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     case 4: */
/**         score = IMG_Load("4.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     case 5: */
/**         score = IMG_Load("5.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     case 6: */
/**         score = IMG_Load("6.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     case 7: */
/**         score = IMG_Load("7.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     case 8: */
/**         score = IMG_Load("8.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     case 9: */
/**         score = IMG_Load("9.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     case 10: */
/**         score = IMG_Load("10.png"); */
/**         SDL_BlitSurface(score, NULL, ecran, &positionscore); */
/**         break; */
/**     } */
/**  */
/**  */
/**     SDL_Flip(ecran); */
/**     pause(); */
/**  */
/**     SDL_FreeSurface(score); */
/**     SDL_Quit(); */
/**  */
/**     return EXIT_SUCCESS; */
/** } */
/** SDL_Color GetPixel(SDL_Surface* background_mask, int x, int y) */
/** { */
/**     SDL_Color color; */
/**     Uint32 col = 0; */
/**     char* pPosition = (char*)background_mask->pixels; */
/**     pPosition += (background_mask->pitch * y); */
/**     pPosition += (background_mask->format->BytesPerPixel * x); */
/**     memcpy(&col, pPosition, background_mask->format->BytesPerPixel); */
/**     SDL_GetRGB(col, background_mask->format, &color.r, &color.g, &color.b); */
/**     return (color); */
/** } */
/**  */
/** int detectCollPP(SDL_Surface* BackgroundMasque, SDL_Rect Personnage) */
/** { */
/**  */
/**     SDL_Color colobs; */
/**  */
/**     SDL_Color colgotten; */
/**  */
/**     SDL_Rect Pos[8]; */
/**  */
/**     int collision = 0, i = 0; */
/**     colobs.r = 0; */
/**     colobs.g = 0; */
/**     colobs.b = 0; */
/**  */
/**     Pos[0].x = Personnage.x; */
/**  */
/**     Pos[0].y = Personnage.y; */
/**  */
/**     Pos[1].x = Personnage.x + (Personnage.w / 2); */
/**  */
/**     Pos[1].y = Personnage.y; */
/**  */
/**     Pos[2].x = Personnage.x + Personnage.w; */
/**  */
/**     Pos[2].y = Personnage.y; */
/**  */
/**     Pos[3].x = Personnage.x; */
/**  */
/**     Pos[3].y = Personnage.y + (Personnage.h / 2); */
/**  */
/**     Pos[4].x = Personnage.x; */
/**  */
/**     Pos[4].y = Personnage.y + Personnage.h; */
/**  */
/**     Pos[5].x = Personnage.x + (Personnage.w / 2); */
/**  */
/**     Pos[5].y = Personnage.y + Personnage.h; */
/**  */
/**     Pos[6].x = Personnage.x + Personnage.w; */
/**  */
/**     Pos[6].y = Personnage.y + Personnage.h; */
/**  */
/**     Pos[7].x = Personnage.x + Personnage.w; */
/**  */
/**     Pos[7].y = Personnage.y + (Personnage.h / 2); */
/**  */
/**     while ((i <= 7) && (collision == 0)) { */
/**         colgotten = GetPixel(BackgroundMasque, Pos[i].x, Pos[i].y); */
/**  */
/**         if ((colobs.r == colgotten.r) && (colobs.b == colgotten.b) && */
/**  */
/**             (colobs.g == colgotten.g)) { */
/**  */
/**             collision = 1; */
/**  */
/**         } else { */
/**  */
/**             i++; */
/**         } */
/**     } */
/**  */
/**     return collision; */
/** } */
