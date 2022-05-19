#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int izbornik(const char* const datClanovi) {

	printf("_____________________________________\n\n\n");
	printf("SNAKES & LADDDERES: \n\n");
	printf("_____________________________________\n\n");

	printf("Unesi \"1\": Nova igra (vs AI)\n");
	printf("Unesi \"2\": Multiplayer \n");
	printf("Unesi \"3\": Leaderboard \n");
	printf("Unesi \"4\":  \n");
	printf("Unesi \"5\": IZLAZ IZ IGRE ! \n\n");
	printf("_____________________________________\n\n");

	int cond = 0;

	scanf("%d", &cond);

	static CLAN* poljeClanova = NULL;
	static CLAN* pronadeniClan = NULL;

	switch (cond) {
	case 1:
		dodajKorisnika(datClanovi);
		break;
	case 2:
		if (poljeClanova != NULL) {
			free(poljeClanova);
			poljeClanova = NULL;
		}

		poljeClanova = (CLAN*)ucitajKorisnike(datClanovi);

		if (poljeClanova == NULL) {
			exit(EXIT_FAILURE);
		}
		break;
	case 3:
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