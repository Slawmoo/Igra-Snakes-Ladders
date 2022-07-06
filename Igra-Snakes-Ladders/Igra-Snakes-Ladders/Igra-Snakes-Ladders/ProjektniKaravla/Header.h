#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "dataType.h"

//int prime(int);
//int primesDoNum(int);
int izbornik();
void start_board(void);
int bacanje();
void primjeniKocku(int, PLAYER_IG* );
//void place_players(PLAYER_IG*, PLAYER_IG*);
int rndNum(int DG,int GG);
int isUniqueArray(int* polje, int len);
short gameLoopv_2(PLAYER_IG, PLAYER_IG*, PLAYER_IG, PLAYER_IG* ,int*,int); 
void place_playersAnal(PLAYER_IG*, PLAYER_IG*, int*, int);// , PLAYER_IG*);
int checkingUniqness(int*, const int, int);
//int testVrijednosti(int,int, int, int*, int*, int*, int*, int*, int*,int*);
void textColorReset();
void textcolor(int , int );
void ocistiKonzolu();
int izlazIzPrograma();

//void ispisiBoard(char*);
//char* napraviBoard(int *);
//int miniGame(PLAYER_IG);
//PLAYER_IG genPlayer();
//void setPlayers(char*,int , PLAYER_IG*, PLAYER_IG*);
/*void kreiranjeDatoteke(const char* const);
void dodajKorisnika(const char* const);
void* ucitajKorisnike(const char* const);
void ispisiSveKorisnike(const CLAN* const);
void* pretraziClanove(CLAN* const);
*/
#endif
