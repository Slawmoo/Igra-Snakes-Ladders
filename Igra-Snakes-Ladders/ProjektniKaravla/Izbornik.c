#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int izbornik(/*const char* const datClanovi*/) {

	printf("\n\n_____________________________________\n\n\n");
	printf("SNAKES & LADDDERES: \n\n");
	printf("_____________________________________\n\n");

	printf("Unesi \"1\": Nova igra (vs AI)\n");
	/*printf("Unesi \"2\": Multiplayer \n");
	printf("Unesi \"3\": Leaderboard \n");*/
	printf("Unesi \"5\": IZLAZ IZ IGRE ! \n\n");
	printf("_____________________________________\n\n");

	int cond = 0;

	scanf("%d", &cond);

	switch (cond) {
	case 1://NOVA IGRA
		ocistiKonzolu();
		char* pBoard= napraviBoard(); // Kreira matricu 10x10
	
		// Generira igraèe na prvo polje
		
		//PLAYER_IG p1 = genPlayer();//Stvaranje igraca 
		//PLAYER_IG p2 = genPlayer();
		PLAYER_IG p1;
		PLAYER_IG p2;
		strcpy(p1.nick, "ssapd");
		p1.boardPosition = 100;
		p1.tag = 'X';
		strcpy(p2.nick, "asldasd");
		p2.boardPosition = 99;
		p2.tag = '0';
		ocistiKonzolu();
		printf("Player 1:\n\tNick: %s\n\tBoardPos: %d\n\tTag: %c",p1.nick, p1.boardPosition,p1.tag);// Ispis igraca
		printf("\n\nPlayer 2:\n\tNick: %s\n\tBoardPos: %d\n\tTag: %c", p2.nick, p2.boardPosition, p2.tag);
		//ispisiBoard(pBoard);
		printf("\n\n");
		setPlayers(pBoard,p1,p2); // i print matrice novo nastale
		
		printf("\n\n\nStisni tipku za dalje...");// Gumb za igranje mini igre
		//getch();
		
		int rezMini = miniGame();// Mini igra pogadjanje (0-9)
		if (rezMini == 1)//prvi player dobio game
		{

		}
		else if (rezMini == 2)//drugi player dobio game
		{

		}
		else {//mini game prekinut
			
		}
		free(pBoard);

		// Basic AI za bota
		// Gumb za bacacnje kocke
		// Refresh matrice da se vidi promjema nakon bacanja
		// Randomizira zmije i ljestve
		// Tumaè znakova ispod matrice za elemente na matrici
		break;
	/*case 2://MULTIPLAYER 2 IRL igraca
		
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
		*/
	case 5:
		cond = izlazIzPrograma();
		break;
	
	default:
		cond = 0;
	}

	return cond;
}