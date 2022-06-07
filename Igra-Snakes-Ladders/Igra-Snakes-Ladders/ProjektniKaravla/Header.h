#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "dataType.h"

int izbornik(/*const char* const*/);
void ispisiBoard(char*);
char* napraviBoard();
int izlazIzPrograma();
void ocistiKonzolu();
PLAYER_IG genPlayer();
void setPlayers(char*, PLAYER_IG*, PLAYER_IG*);
int miniGame();
int bacanje();
void primjeniKocku(int, PLAYER_IG*);
/*void kreiranjeDatoteke(const char* const);
void dodajKorisnika(const char* const);
void* ucitajKorisnike(const char* const);
void ispisiSveKorisnike(const CLAN* const);
void* pretraziClanove(CLAN* const);

*/
#endif
