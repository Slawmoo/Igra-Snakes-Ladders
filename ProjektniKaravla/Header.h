#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "dataType.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>

char siguranUnosCHARa(char*);
int siguranUnosINTa(char*, int, int);
int clean_stdin();
int izbornik();
int bacanje();
void primjeniKocku(int, PLAYER_IG*, int*, int);
int rndNum(int DG, int GG);
int isUniqueArray(int* polje, int len);
short gameLoopv_2(PLAYER_IG, PLAYER_IG*, PLAYER_IG, PLAYER_IG*, int*, int, int*, int);
void place_playersAnal(PLAYER_IG*, PLAYER_IG*, int*, int);
int checkingUniqness(int*, const int, int);
void textColorReset();
void textcolor(int, int);
int izlazIzPrograma();

int kreirajPlayera(void);
int provjeraNick(int, char*);
int provjeraID(int, int);
int provjeraTaga(int, char*);
void obirisiPlayera(int);

int brojPlayera(void);
PLAYER_IG trazenjeID(int, int);

int ispisiLeaderboard(int z);//izbornik leaderboard
/*
void promjenaNicka(int s, int z);//promjena nicka, id, taga
void promjenaIDa(int s, int z);//promjena nicka, id, taga
void promjenaTaga(int s, int z);//promjena nicka, id, taga

void obirisiZaposlenika(int z);
int sortiraj(int z);
void sortirajPlacaVeca(int z);
void sortirajPlacaManja(int z);
void zamjena(PLAYER_IG* veci, PLAYER_IG* manji);
void sortirajIme(int z);
void trazenjeID(int k);
*/

//int miniGame(PLAYER_IG);

#endif
