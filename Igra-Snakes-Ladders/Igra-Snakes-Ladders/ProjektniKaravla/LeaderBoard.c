#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
/*
int leaderBoard(const char* const datClanovi) {

	printf("_____________________________________\n\n\n");
	printf("			LEADERBOARD: \n\n");
	printf("_____________________________________\n\n");
	//			  ________________________________________________________________________
	//Leaderboard | Ranking | NickIgraca | BrojPobjeda | MinBrojPoteza | NajboljeVrijeme | 
	//			  ________________________________________________________________________
	//Leaderboard | Ranking | NickIgraca | BrojPobjeda | MinBrojPoteza | NajboljeVrijeme |
	//			  ________________________________________________________________________
	//Leaderboard | Ranking | NickIgraca | BrojPobjeda | MinBrojPoteza | NajboljeVrijeme |
	//			  ________________________________________________________________________
	//spremanje u bin ili txt datoteku 
	
	int cond = 0;

	scanf("%d", &cond);

	static CLAN* poljeClanova = NULL;
	static CLAN* pronadeniClan = NULL;

	switch (cond) {
	case 1://NOVA IGRA

		break;
	case 2://MULTIPLAYER 2 IRL igraca

		//exit(EXIT_FAILURE);
		break;
	case 3://LEADERBOARD

		ispisiSveKorisnike(poljeClanova);
		break;
	case 4:
		pronadeniClan = (CLAN*)pretraziClanove(poljeClanova);

		if (pronadeniClan != NULL) {
			printf("ID: %d\n", pronadeniClan->id);
			printf("Ime: %s\n", pronadeniClan->ime);
			printf("Prezime: %s\n", pronadeniClan->prezime);
			printf("Adresa: %s\n", pronadeniClan->adresa);
			printf("Broj mobitela: %s\n", pronadeniClan->brojMobitela);
			printf("Broj podignutih filmova: %d\n", pronadeniClan->brojPodignutihFilmova);
		}
		else {
			printf("Ne postoji clan s tim ID-em.\n");
		}

		break;

	case 5:
		cond = izlazIzPrograma(poljeClanova);
		break;
	default:
		cond = 0;
	}

	return cond;
}
*/