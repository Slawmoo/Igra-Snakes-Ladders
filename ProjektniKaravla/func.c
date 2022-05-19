#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

static int brojClanova = 0;
static int brojFilmova = 0;

void kreiranjeDatoteke(const char* const dat) {

	brojClanova = 0;

	FILE* fP = fopen(dat, "wb");

	if (fP == NULL) {
		perror("Grešak pri kreiranju datoteke");
		exit(EXIT_FAILURE);
	}

	fwrite(&brojClanova, sizeof(int), 1, fP);

	printf("Datoteka Kreirana\n\n");
	fclose(fP);

}

void dodajKorisnika(const char* const dat) {

	FILE* fP = fopen(dat, "rb+");

	if (fP == NULL) {
		perror("Greska u dodavanju clanova u datoteku clanovi.bin");
		exit(EXIT_FAILURE);
	}

	//citamo datoteku i zapisujemo broj clanova u varijablu brojClanova
	fread(&brojClanova, sizeof(int), 1, fP);
	printf("Broj clanova: %d\n\n", brojClanova);

	CLAN temp = { 0 };
	temp.id = brojClanova + 1;
	getchar();
	printf("Unesite ime clana: \n");
	scanf("%24[^\n]", temp.ime);
	getchar();

	printf("Unesite prezime clana: \n");
	scanf("%24[^\n]", temp.prezime);
	getchar();

	printf("Unesite adresu clana: \n");
	scanf("%49[^\n]", temp.adresa);
	getchar();

	printf("Unesite broj mobitela clana: \n");
	scanf("%10[^\n]", temp.brojMobitela);
	getchar();
	temp.brojPodignutihFilmova = 0;
	/*
	do {
		printf("Unesite broj podignutih filmova (0-4): \n");
		scanf("%d", temp.brojPodignutihFilmova);
	} while (temp.brojPodignutihFilmova < 0 || temp.brojPodignutihFilmova > 4);
	*/
	//pomicemo se na kraj datoteke i zapisujemo novog clana tamo
	fseek(fP, sizeof(CLAN) * brojClanova, SEEK_CUR);
	fwrite(&temp, sizeof(CLAN), 1, fP);
	printf("Clan dodan\n\n");

	// vracanje na pocetak datoteke i povecavanje brojaca
	rewind(fP);
	brojClanova++;


	// azuriranje brojaca
	fwrite(&brojClanova, sizeof(int), 1, fP);

	fclose(fP);
}



void* ucitajKorisnike(const char* const dat) {

	FILE* fP = fopen(dat, "rb");

	if (fP == NULL) {
		perror("Greska pri ucitavanju korisnika iz datoteke clanovi.bin");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(&brojClanova, sizeof(int), 1, fP);
	printf("Broj clanova: %d\n", brojClanova);

	CLAN* poljeClanova = (CLAN*)calloc(brojClanova, sizeof(CLAN));

	if (poljeClanova == NULL) {
		perror("Zauzimanje memorije za studente");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(poljeClanova, sizeof(CLAN), brojClanova, fP);

	printf("Svi clanovi uspjesno ucitani.\n\n");

	return poljeClanova;
}

void ispisiSveKorisnike(const CLAN* const polje) {

	if (polje == NULL) {
		printf("Polje clanova prazno\n");
		return;
	}

	for (int i = 0; i < brojClanova; i++) {
		printf("Clan broj %d\tID: %d\tIme: %s\tPrezime: %s\tAdresa: %s\tMobitel: %s\tBroj posudenih filmova: %d\n\n",
			i + 1,
			(polje + i)->id,
			(polje + i)->ime,
			(polje + i)->prezime,
			(polje + i)->adresa,
			(polje + i)->brojMobitela,
			(polje + i)->brojPodignutihFilmova);
	}
}

void* pretraziClanove(CLAN* const polje) {

	if (polje == NULL) {
		printf("Polje clanova prazno\n");
		return NULL;
	}

	int trazeniId;

	printf("Unesite ID clana kojeg trazite: \n");
	scanf("%d ", &trazeniId);

	// ako nademo clana vracamo cijeli element polja s trazenim id-em
	for (int i = 0; i < brojClanova; i++) {

		if (trazeniId == (polje + i)->id) {
			printf("Clan pronaden.\n");

			return (polje + i);
		}
	}

	// vracamo NULL u slucaju da ne nademo nijednog clana s tim id
	return NULL;
}

int izlazIzPrograma(CLAN* poljeClanova) {

	free(poljeClanova);
	printf("Zelite li izaci iz programa ?");
	printf("Utipkajte \"da\" ako želite u suprotno utipkajte\"ne\"!\n");
	char potvrda[3] = { '\0' };
	scanf("%2s", potvrda);
	if (!strcmp("da", potvrda)) {
		return 0;
	}
	else {
		return 1;
	}
}