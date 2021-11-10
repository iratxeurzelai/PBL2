#ifndef GRAPHICS_H
#define GRAPHICS_H


#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480

int sgHasieratu();
void sgItxi();//Sin opciones
void pantailaGarbitu();
void pantailaBerriztu();
int irudiaMarraztu(SDL_Texture* texture, SDL_Rect *pDest);
SDL_Renderer* getRenderer(void);

#endif


