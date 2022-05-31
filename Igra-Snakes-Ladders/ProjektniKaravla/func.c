#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
#include <math.h>

//static int brojClanova = 0;

char* napraviBoard() {
	char* board = calloc(101,sizeof(char));
	for (int i = 0; i < 100; i++)
	{
		*(board + i) = '_';
	}
	ispisiBoard(board);
	return board;
}
void ispisiBoard(char* board) {
	printf("\t");
	for (int i = 1; i < 101; i++)
	{
		printf("%c ", *(board + (i-1)));
		if (i%10==0)
		{
			printf("\n\t");
		}
	}
}
int izlazIzPrograma() {

	//free(board);
	printf("\nZelite li izaci iz programa ?");
	printf("\n\nUtipkajte \"y\" ako želite u suprotno utipkajte\"n\"!\n");
	char potvrda[2] = { '\0' };
	scanf("%1s", potvrda);
	if (!strcmp("y", potvrda)) {
		return 0;
	}
	else {
		return 1;
	}
}
void ocistiKonzolu() {
	system("cls");
	printf("\n\n");
}
PLAYER_IG genPlayer() {
	PLAYER_IG p1;
	printf("\nUnesi Nick:\n");
	scanf("%24s[^\n]", p1.nick);
	printf("\nUnesi oznaku za igraca:\n");
	scanf("%1s[^\n]", &p1.tag);
	p1.boardPosition = 100;
	return p1;
}
void setPlayers(char* pBoard, PLAYER_IG p1, PLAYER_IG p2) {
	
	for (int i = 100; i > 1; i--)
	{
		if (i == p1.boardPosition) 
		{
			*(pBoard + (i - 1)) = p1.tag;
		}
		if (i == p2.boardPosition) 
		{
			*(pBoard + (i - 1)) = p2.tag;
			if (p2.boardPosition == p1.boardPosition) {
				*(pBoard + (i - 1)) = '&';
			}
		}
	}
	ispisiBoard(pBoard);
}
int miniGame() {
	
	printf("\n\tMINI GAME\n\tHIGHER LOWER");
	printf("Izaberi pocetni broj (0-9):\n\n");//ako igrac sluc izabere tocan broj ima 2 bacanja
	float startNum;
	scanf("%f", &startNum);
	ceil(startNum);
	int izbor[] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
	int sicNum = rand() % 10;
	printf("0, 1, 2, 3, 4, 5, 6, 7, 8, 9");
	printf("Start broj je: %d", startNum);
	printf("Za visi broj unesi \"h\" ili \"H\" za nizi \"l\" ili \"L\"");
	char potvrda[2] = { '\0' };
	scanf("%1s", potvrda);
	if (startNum == sicNum) {
		//player 1 2x bacanja
		return 1;
	}
	else {
		do {
			if (strcmp("h", potvrda) || strcmp("H", potvrda)) {
				return 2;
			}
			else if (strcmp("l", potvrda) || strcmp("L", potvrda)) {
				return 3;
			}
			else {
				printf("Unesena je nepoznata vrijednost pokusaj ponovno...\n\n");
			}
		} while ((potvrda != "l") || (potvrda != "L") || (potvrda != "h") || (potvrda != "H"));
	}/*for (int i = 0; i < 10; i++)
	{
		printf("Sicret num: %d\n", sicNum);
		sicNum = rand() % 10;
	}*/

	return 0;
}

/*
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
}*/

