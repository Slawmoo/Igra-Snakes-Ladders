#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "dataType.h"

int izbornik();
void start_board(void);
int bacanje();
void primjeniKocku(int, PLAYER_IG* );
//void place_players(PLAYER_IG*, PLAYER_IG*);

short gameLoopv_2(PLAYER_IG, PLAYER_IG*); //(PLAYER_IG, PLAYER_IG, PLAYER_IG*, PLAYER_IG*);
//short gameLoop(PLAYER_IG, PLAYER_IG, PLAYER_IG*, PLAYER_IG*);
void place_playersAnal(PLAYER_IG*);// , PLAYER_IG*);

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
