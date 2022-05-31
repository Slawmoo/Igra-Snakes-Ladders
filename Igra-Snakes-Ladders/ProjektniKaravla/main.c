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
Cilj igraèa doæi u zadnji kvadrat igraèe ploèe(matrice) u što manje poteza								//RND NUM GEN

ili prije suparnièkog igraèa																			//RND NUM GEN

na ploèi su nasumièno generirane zmije (vraæaju igraèa prema nazad) i ljestve (šalju igraèa naprijed),  //RND NUM GEN + Static Duljine Snak&Ladd

potezi se rade prema nasumièno generiranoj brojci (kocki s 6 strana od 1-6),							//Kockicaa

simulacija igraèe ploèe u konzoli,																		//mozda animacije ili samo teleport igraèa u dijelovima preko polja 

praæenje statistika igraèa,																				//
																										//brisanje leaderboarda, stats reset
																										//,pretrazivanje igraca po rednom broju spremljenom u leaderboardu,
																										//,spremanje u datoteku, sortiranje, matrica za leaderboard

mini-igra za odreðivanja prava na bacanje kocke (pogaðanje broja, najbliži traženom broju pobjeðuje)	//nizovi - dinamièko zauzimanje memorije pokazivaèi
*/