#include "globals.h"
#include "SDL2/SDL.h"
#include <SDL_mixer.h>
#include <stdio.h>
#include <unistd.h>
#include "ebentoak.h"
#include "soinua.h"
#include "imagen.h"
#include "irudiakEtaSoinuak.h"
#include "graphics.h"
#include <wiringPi.h>
#include "ourWiringPi.h"
#include <time.h>

typedef struct Grabazioa {
	int nota;
	struct Grab* ptrHurrengoa;
} GRAB;

int JOTAKO_TEKLA();
void grabatu(int tekla, int lehenengoa);
GRAB* sartuBukaeran(GRAB*pHasiera, GRAB* pBerria);
void erreproduzitu(int aukera, int idAudio[]);



int main() {
	int idAudio[13];
	int instrumentoa = -1;
	int nota = -1;

	int grabazioa = 0;
	int lehenengoa=0;
	int reproduzioa=0;

	//wiringPi...
	wiringPiHasieratu();


	printf("Aukeratu:\n1 Piano\n2 Xilofono\n3 Saxofon\n4 Tronpeta\n5 Oof\n0 atera\n");

	if (sgHasieratu() == -1) {
		fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
		return 1;
	}
/////////////////////////////////////////////////////////////////////////


	do {

		while((instrumentoa!=PIANO)&&(instrumentoa!=XILOFONO)&&(instrumentoa!=SAXOFOIA)&&(instrumentoa!=TRONPETA)&&(instrumentoa!=OOF)&&(instrumentoa!=ATERA)) {
			instrumentoa = JOTAKO_TEKLA();
		}

		audioInit();
		Mix_AllocateChannels(16);
		if (instrumentoa == PIANO) {
			idAudio[0] = loadSound(pDO);
			idAudio[1] = loadSound(pDO_S);
			idAudio[2] = loadSound(pRE);
			idAudio[3] = loadSound(pRE_S);
			idAudio[4] = loadSound(pMI);
			idAudio[5] = loadSound(pFA);
			idAudio[6] = loadSound(pFA_S);
			idAudio[7] = loadSound(pSOL);
			idAudio[8] = loadSound(pSOL_S);
			idAudio[9] = loadSound(pLA);
			idAudio[10] = loadSound(pLA_S);
			idAudio[11] = loadSound(pSI);
		} else if (instrumentoa == XILOFONO) {
			idAudio[0] = loadSound(xDO);
			idAudio[1] = loadSound(xDO_S);
			idAudio[2] = loadSound(xRE);
			idAudio[3] = loadSound(xRE_S);
			idAudio[4] = loadSound(xMI);
			idAudio[5] = loadSound(xFA);
			idAudio[6] = loadSound(xFA_S);
			idAudio[7] = loadSound(xSOL);
			idAudio[8] = loadSound(xSOL_S);
			idAudio[9] = loadSound(xLA);
			idAudio[10] = loadSound(xLA_S);
			idAudio[11] = loadSound(xSI);
		} else if (instrumentoa == SAXOFOIA) {
			idAudio[0] = loadSound(sDO);
			idAudio[1] = loadSound(sDO_S);
			idAudio[2] = loadSound(sRE);
			idAudio[3] = loadSound(sRE_S);
			idAudio[4] = loadSound(sMI);
			idAudio[5] = loadSound(sFA);
			idAudio[6] = loadSound(sFA_S);
			idAudio[7] = loadSound(sSOL);
			idAudio[8] = loadSound(sSOL_S);
			idAudio[9] = loadSound(sLA);
			idAudio[10] = loadSound(sLA_S);
			idAudio[11] = loadSound(sSI);
		} else if (instrumentoa == TRONPETA) {
			idAudio[0] = loadSound(tDO);
			idAudio[1] = loadSound(tDO_S);
			idAudio[2] = loadSound(tRE);
			idAudio[3] = loadSound(tRE_S);
			idAudio[4] = loadSound(tMI);
			idAudio[5] = loadSound(tFA);
			idAudio[6] = loadSound(tFA_S);
			idAudio[7] = loadSound(tSOL);
			idAudio[8] = loadSound(tSOL_S);
			idAudio[9] = loadSound(tLA);
			idAudio[10] = loadSound(tLA_S);
			idAudio[11] = loadSound(tSI);
		} else if (instrumentoa == OOF) {
			idAudio[0] = loadSound(oDO);
			idAudio[2] = loadSound(oRE);
			idAudio[4] = loadSound(oMI);
			idAudio[5] = loadSound(oFA);
			idAudio[7] = loadSound(oSOL);
			idAudio[9] = loadSound(oLA);
			idAudio[11] = loadSound(oSI);
		}
		int aurrekoa = -1;
		int zenbat[1000];
		int kont = 0;

		while ((nota != ATERA)&&(nota!=PIANO)&&(nota!=XILOFONO)&&(nota!=SAXOFOIA)&&(nota!=TRONPETA)&&(nota!=OOF)&&(nota!=ATERA)) {
			aurrekoa = nota;
			nota = JOTAKO_TEKLA();
			if(nota == aurrekoa) zenbat[kont]++;
			else {
				printf("%i, ", nota);
				kont++;
				//Estas con loadSound();
				if (nota == DO_T) Mix_PlayChannel(1, soinuak[idAudio[0]], 0);
				if (nota == RE_T) Mix_PlayChannel(2, soinuak[idAudio[1]], 0);
				if (nota == MI_T) Mix_PlayChannel(3, soinuak[idAudio[2]], 0);
				if (nota == FA_T) Mix_PlayChannel(4, soinuak[idAudio[3]], 0);
				if (nota == SOL_T) Mix_PlayChannel(5, soinuak[idAudio[4]], 0);
				if (nota == LA_T) Mix_PlayChannel(6, soinuak[idAudio[5]], 0);
				if (nota == SI_T) Mix_PlayChannel(7, soinuak[idAudio[6]], 0);
				if (nota == DO_ST) Mix_PlayChannel(8, soinuak[idAudio[7]], 0);
				if (nota == RE_ST) Mix_PlayChannel(9, soinuak[idAudio[8]], 0);
				if (nota == FA_ST) Mix_PlayChannel(10, soinuak[idAudio[9]], 0);
				if (nota == SOL_ST) Mix_PlayChannel(11, soinuak[idAudio[10]], 0);
				if (nota == LA_ST) Mix_PlayChannel(12, soinuak[idAudio[11]], 0);
				if(nota == GRABATU) grabazioa = 1;
				if(nota == ERREPRODUZITU) reproduzioa=1;
				if(grabazioa == 1 && nota != -1) {
					grabatu(nota, lehenengoa);
					lehenengoa=1;
				}
				if(reproduzioa==1){
					erreproduzitu(instrumentoa, idAudio);
					reproduzioa=0;
					lehenengoa=0;
					grabazioa=0;
					remove("grabazioa.txt");
				}
			}
		}
		instrumentoa = nota;
		sleep(1);
		nota = -1;
		audioTerminate();
	} while(instrumentoa != ATERA);
	audioTerminate();
	sgItxi();
	return 0;
}

int JOTAKO_TEKLA() {
	int ret = -1;
	int pultsatuta[25];
	pultsatuta[0] = -1;
	pultsatuta[1] = -1;
	pultsatuta[2] = -1;
	pultsatuta[3] = -1;
	pultsatuta[4] = -1;
	pultsatuta[5] = -1;
	pultsatuta[6] = -1;
	pultsatuta[7] = -1;
	pultsatuta[8] = -1;
	pultsatuta[9] = -1;
	pultsatuta[10] = -1;
	pultsatuta[11] = -1;
	pultsatuta[12] = -1;
	pultsatuta[13] = -1;
	pultsatuta[14] = -1;
	pultsatuta[15] = -1;
	pultsatuta[16] = -1;
	pultsatuta[17] = -1;
	pultsatuta[18] = -1;
	pultsatuta[19] = -1;
	pultsatuta[20] = -1;
	pultsatuta[21] = -1;
	pultsatuta[22] = -1;
	pultsatuta[23] = -1;
	pultsatuta[24] = -1;
	pultsatuta[25] = -1;

	if ((pultsatuta[0] = digitalRead (DO_T)) == HIGH) ret = DO_T;
	if ((pultsatuta[1] = digitalRead (RE_T)) == HIGH) ret = RE_T;
	if ((pultsatuta[2] = digitalRead (MI_T)) == HIGH) ret = MI_T;
	if ((pultsatuta[3] = digitalRead (FA_T)) == HIGH) ret = FA_T;
	if ((pultsatuta[4] = digitalRead (SOL_T)) == HIGH) ret = SOL_T;
	if ((pultsatuta[5] = digitalRead (LA_T)) == HIGH) ret = LA_T;
	if ((pultsatuta[6] = digitalRead (SI_T)) == HIGH) ret = SI_T;
	if ((pultsatuta[7] = digitalRead (DO_ST)) == HIGH) ret = DO_ST;
	if ((pultsatuta[8] = digitalRead (RE_ST)) == HIGH) ret = RE_ST;
	if ((pultsatuta[9] = digitalRead (FA_ST)) == HIGH) ret = FA_ST;
	if ((pultsatuta[10] = digitalRead (SOL_ST)) == HIGH) ret = SOL_ST;
	if ((pultsatuta[11] = digitalRead (LA_ST)) == HIGH) ret = LA_ST;
	//sf
	if ((pultsatuta[13] = digitalRead (PIANO)) == HIGH) ret = PIANO;
	if ((pultsatuta[14] = digitalRead (XILOFONO)) == HIGH) ret = XILOFONO;
	if ((pultsatuta[15] = digitalRead (SAXOFOIA)) == HIGH) ret = SAXOFOIA;
	if ((pultsatuta[16] = digitalRead (TRONPETA)) == HIGH) ret = TRONPETA;
	if ((pultsatuta[17] = digitalRead (OOF)) == HIGH) ret = OOF;
	if ((pultsatuta[18] = digitalRead (GRABATU)) == HIGH) ret = GRABATU;
	if ((pultsatuta[19] = digitalRead (ERREPRODUZITU)) == HIGH) ret = ERREPRODUZITU;
	if ((pultsatuta[20] = digitalRead (PAUSATU)) == HIGH) ret = PAUSATU;
	if ((pultsatuta[21] = digitalRead (ATERA)) == HIGH) ret = ATERA;

	return ret;
}

void grabatu(int nota, int lehenengoa) {
	if (nota == DO_T || nota == RE_T || nota == MI_T || nota == FA_T || nota == SOL_T || nota == LA_T || nota == SI_T || nota == DO_ST || nota == RE_ST || nota == FA_ST || nota == SOL_ST || nota == LA_ST) {
	FILE* tuberiaFitx1;
	if (lehenengoa == 0) tuberiaFitx1 = fopen("grabazioa.txt", "w");
	if (lehenengoa == 1) tuberiaFitx1 = fopen("grabazioa.txt", "a");
	fprintf(tuberiaFitx1, "%i, ", nota);
	fclose(tuberiaFitx1);
	}
}


void erreproduzitu(int instrumentoa, int idAudio[]) {
	FILE* fitxategia;
	int zenbat = 1, zenbaki = 0, ebentu = 0, pause = 0, kont = 0;
	int tekla = -1;

	GRAB* pHasiera = 0;
	fitxategia = fopen("grabazioa.txt", "r");

	if (fitxategia > 0) {
		do {
			zenbat = fscanf(fitxategia, "%i, ", &tekla);

			GRAB* pBerria;
			pBerria = (GRAB *)malloc(sizeof(GRAB));
			pBerria->nota = tekla;

			pHasiera = sartuBukaeran(pHasiera, pBerria);

		} while (zenbat > 0);
		fclose(fitxategia);
	}

	GRAB *pAux;
	pAux = pHasiera;

	do {
		if (zenbaki % 200000 == 0 && pause != 1) {
			tekla = pAux->nota;
			pAux = pAux->ptrHurrengoa;
		}
		if (tekla == DO_T) playSound(idAudio[0]);
		if (tekla == RE_T) playSound(idAudio[1]);
		if (tekla == MI_T) playSound(idAudio[2]);
		if (tekla == FA_T) playSound(idAudio[3]);
		if (tekla == SOL_T) playSound(idAudio[4]);
		if (tekla == LA_T) playSound(idAudio[5]);
		if (tekla == SI_T) playSound(idAudio[6]);
		if (tekla == DO_ST) playSound(idAudio[7]);
		if (tekla == RE_ST) playSound(idAudio[8]);
		if (tekla == FA_ST) playSound(idAudio[9]);
		if (tekla == SOL_ST) playSound(idAudio[10]);
		if (tekla == LA_ST) playSound(idAudio[11]);
		zenbaki++;
		tekla = -1;
		ebentu = JOTAKO_TEKLA();
		if (ebentu == PAUSATU){
			kont++;
			if (kont % 2 == 0) pause = 0;
			else pause=1;
		}
	} while (pAux->ptrHurrengoa != NULL && ebentu != ATERA);
}

GRAB* sartuBukaeran(GRAB* pHasiera, GRAB* pBerria) {
	GRAB* aux = NULL;
	aux = pHasiera;

	if (pHasiera == NULL) {
		pBerria->ptrHurrengoa = pHasiera;
		pHasiera = pBerria;
	}
	else {
		while (aux->ptrHurrengoa != NULL) {
			aux = aux->ptrHurrengoa;
		}
		aux->ptrHurrengoa = pBerria;
		pBerria->ptrHurrengoa = NULL;
	}
	return pHasiera;
}
