
#include "Header.h"

int main(void) {

	int cond = 4;
	srand((unsigned)time(NULL));


	while (cond) {
		cond = izbornik();// (datoteka) - je bila u () od izbornika
	}
	printf("\n\n\tZavrsetak programa!");

	return 0;
}
/*
++Cilj igraca doci u zadnji kvadrat igrace ploce(matrice) u sto manje poteza								//RND NUM GEN++

++ili prije suparnickog igraca																			//RND NUM GEN++

++na ploci su nasumicno generirane zmije (vracaju igraca prema nazad) i ljestve (salju igraca naprijed),  //RND NUM GEN + Static Duljine Snak&Ladd++

++potezi se rade prema nasumicno generiranoj brojci (kocki s 6 strana od 1-6),							//Kockicaa++

++simulacija igrace ploce u konzoli,																		//samo teleport igraca preko polja ++

pracenje statistika igraca,																				//
																										//brisanje leaderboarda, stats reset
																										//,pretrazivanje igraca po rednom broju spremljenom u leaderboardu,
																										//,spremanje u datoteku, sortiranje, matrica za leaderboard
*/