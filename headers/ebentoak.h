#ifndef EBENT0AK_H
#define EBENT0AK_H


typedef struct S_POSIZIOA
{
  float x;
  float y;
} POSIZIOA;

/*
  Helburua: Funztio hau tekla bat sakatu arte zain dago,
  eta ondoren zenbaki oso baten bitartez zein sakatu den adieraziko digu.
  Sarrera:
  Irteera: Sakatuta teklaren identifikadorea
*/
int ebentuaJasoGertatuBada(void);
POSIZIOA saguarenPosizioa();

#define SAGU_MUGIMENDUA  4
#define SAGU_BOTOIA_ESKUMA 5
#define SAGU_BOTOIA_EZKERRA 6
#define GERTAERA_IRTEN 12

#define TECLA_RETURN 13
#define TECLA_ESCAPE 27
#define TECLA_SPACE 32
#define TECLA_0 48
#define TECLA_1 49
#define TECLA_2 50
#define TECLA_3 51
#define TECLA_4 52
#define TECLA_5 53
#define TECLA_6 54
#define TECLA_7 55
#define TECLA_8 56
#define TECLA_9 57
#define TECLA_a 97
#define TECLA_b 98
#define TECLA_c 99
#define TECLA_d 100
#define TECLA_e 101
#define TECLA_f 102
#define TECLA_g 103
#define TECLA_h 104
#define TECLA_i 105
#define TECLA_j 106
#define TECLA_k 107
#define TECLA_l 108
#define TECLA_m 109
#define TECLA_n 110
#define TECLA_o 111
#define TECLA_p 112
#define TECLA_q 113
#define TECLA_r 114
#define TECLA_s 115
#define TECLA_t 116
#define TECLA_u 117
#define TECLA_v 118
#define TECLA_w 119
#define TECLA_x 120
#define TECLA_y 121
#define TECLA_z 122
#define TECLA_UP 273
#define TECLA_DOWN 274
#define TECLA_RIGHT 275
#define TECLA_LEFT 276

//GPIO: wiringPi
#define TEKLA1 7
#define TEKLA2 0
#define TEKLA3 2
#define TEKLA4 3
#define TEKLA5 12
#define TEKLA6 13
#define TEKLA7 14
#define TEKLA8 30
#define TEKLA9 21
#define TEKLA10 22
#define TEKLA11 23
#define TEKLA12 24
#define TEKLA13 25

#define TEKLA14 15
#define TEKLA15 16
#define TEKLA16 1
#define TEKLA17 4
#define TEKLA18 5
#define TEKLA19 6
#define TEKLA20 10
#define TEKLA21 11
#define TEKLA22 31
#define TEKLA23 26
#define TEKLA24 27
#define TEKLA25 28

#define PIANO 15
#define XILOFONO 16
#define SAXOFOIA 1
#define TRONPETA 4
#define OOF 5
#define GRABATU 6
#define ERREPRODUZITU 10
#define PAUSATU 11
#define ATERA 31


#endif
