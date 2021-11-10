//Esto con un incude de include
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define GRAPHICS

#include <SDL2/SDL.h>

#include "imagen.h"
#include "graphics.h"

SDL_Window* window = NULL;
SDL_Renderer* gRenderer;
int colorR, colorG, colorB;

SDL_Renderer* getRenderer(void) { return gRenderer; }

int sgHasieratu()
{
  int ret = 0;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    fprintf(stderr, "ezin SDL hasieratu: %s\n", SDL_GetError());
    return -1;
  }
  atexit(SDL_Quit);
  window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    fprintf(stderr, "Ezin lehioa sortu: %s\n", SDL_GetError());
    return -1;
  }
  gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  return ret;
}


void sgItxi()
{
  SDL_DestroyWindow(window);
  SDL_Quit();
}


int irudiaMarraztu(SDL_Texture* texture, SDL_Rect *pDest)
{
  SDL_Rect src;

  src.x = 0;
  src.y = 0;
  src.w = pDest->w;
  src.h = pDest->h;
  SDL_RenderCopy(gRenderer, texture, &src, pDest);
  return 0;
}

void pantailaGarbitu()
{
  SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(gRenderer);
}


void pantailaBerriztu()
{
  SDL_RenderPresent(gRenderer);
}
