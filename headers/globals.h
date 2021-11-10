/*
 * globals.h
 *
 *  Created on: 27 may. 2019
 *      Author: unai
 */

#ifndef GLOBALS_H
#define GLOBALS_H



#include <stdio.h>
#include <unistd.h>
#include "soinua.h"
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include "irudiakEtaSoinuak.h"

#define DO_T 7
#define RE_T 0
#define MI_T 2
#define FA_T 3
#define SOL_T 12
#define LA_T 13
#define SI_T 14
#define DO_ST 30
#define RE_ST 21
#define FA_ST 22
#define SOL_ST 23
#define LA_ST 24
Mix_Chunk* soinuak[MAX_SOUNDS];

int ebentu;

#endif
