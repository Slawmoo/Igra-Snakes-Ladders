#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int main(void) {

	int cond = 69;
	srand((unsigned)time(NULL));
	//char* datoteka = "clanovi.bin";

	//kreiranjeDatoteke(datoteka);


	while (cond) {
		cond = izbornik(/*datoteka*/);
	}
	printf("Zavrsetak programa!");

	return 0;
}
/*
Cilj igra�a do�i u zadnji kvadrat igra�e plo�e(matrice) u �to manje poteza								//RND NUM GEN

ili prije suparni�kog igra�a																			//RND NUM GEN

na plo�i su nasumi�no generirane zmije (vra�aju igra�a prema nazad) i ljestve (�alju igra�a naprijed),  //RND NUM GEN + Static Duljine Snak&Ladd

potezi se rade prema nasumi�no generiranoj brojci (kocki s 6 strana od 1-6),							//Kockicaa

simulacija igra�e plo�e u konzoli,																		//mozda animacije ili samo teleport igra�a u dijelovima preko polja 

pra�enje statistika igra�a,																				//
																										//brisanje leaderboarda, stats reset
																										//,pretrazivanje igraca po rednom broju spremljenom u leaderboardu,
																										//,spremanje u datoteku, sortiranje, matrica za leaderboard

mini-igra za odre�ivanja prava na bacanje kocke (poga�anje broja, najbli�i tra�enom broju pobje�uje)	//nizovi - dinami�ko zauzimanje memorije pokaziva�i
*/