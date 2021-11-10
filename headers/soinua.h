/*
 * soinua.h
 *
 *  Created on: 27 may. 2019
 *      Author: unai
 */

#ifndef SOINUA_H_
#define SOINUA_H_

#define MAX_SOUNDS 128



void audioInit();
int loadSound(char *fileName);
int loadTheMusic(char *fileName);
int playSound(int idSound);
int playMusic(void);
void toggleMusic(void);
void audioTerminate();
void musicUnload(void);
void soundsUnload();

#endif /* SOINUA_H_ */
