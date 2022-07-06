#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"



int izbornik(/*const char* const datClanovi*/) {

	printf("\n\n\t\t\t_____________________________________\n\n\n");
	printf("\t\t\t\t SNAKES & LADDDERES: \n\n");
	printf("\t\t\t_____________________________________\n\n");

	printf("\t\t\t     Unesi \"1\": Nova igra (vs AI)\n");
	/*printf("Unesi \"2\": Multiplayer \n");
	printf("Unesi \"3\": Leaderboard \n");*/
    printf("\t\t\t     Unesi \"5\": IZLAZ IZ IGRE ! \n\n");
	printf("\t\t\t_____________________________________\n\n\t\t\t");

	int cond = 0;

	scanf("%d", &cond);
	
	switch (cond) {
	case 1://NOVA IGRA
		//ocistiKonzolu();
		/*int boardSize;
		int* Pboardsize = &boardSize;
		char* pBoard = napraviBoard(Pboardsize) ; // Kreira matricu 10x10
	*/
	// Generira igrače na prvo polje

	//PLAYER_IG p1 = genPlayer();//Stvaranje igraca 
	//PLAYER_IG p2 = genPlayer();
		PLAYER_IG p1;
		PLAYER_IG p2;
		PLAYER_IG* pok1 = &p1;
		PLAYER_IG* pok2 = &p2;
		strcpy(p1.nick, "Player 1");
		p1.boardPositionX = 0;
		p1.boardPositionY = 0;
		p1.tag = 'X';
		strcpy(p2.nick, "Player 2");
		p2.boardPositionX = 0;
		p2.boardPositionY = 0;
		p2.tag = 'Z';
		//ocistiKonzolu();
		//printf("Player 1:\n\tNick: %s\n\tBoardPos: %d\n\tTag: %c",p1.nick, p1.boardPosition,p1.tag);// Ispis igraca
		//printf("\n\nPlayer 2:\n\tNick: %s\n\tBoardPos: %d\n\tTag: %c", p2.nick, p2.boardPosition, p2.tag);
		
		int DG = 0, GG = 9,flag =0,size = 12;;
		
		start_board();
		int numOfLS = 6;
		int arrBoje[] = { 2,3,4,5,6,7,8};//[i0][i1][i2][i3] [i4]  [i5]   [i6]
		int uredeniParovi[6][7];
		int paroviZaProvjeru[6][4];		//[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR] 
		do
		{
			for (int i = 0; i < numOfLS; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					if (j < 4) {
						uredeniParovi[i][j] = rndNum(DG, GG);
						paroviZaProvjeru[i][j] = uredeniParovi[i][j];
					}
					else if (j == 4) {
						uredeniParovi[i][j] = arrBoje[i];
					}
					else if (j == 5) {
						uredeniParovi[i][j] = 1;
					}
					else
					{
						uredeniParovi[i][j] = 0;
					}

				}
			}
			flag = checkingUniqness(paroviZaProvjeru, numOfLS, 4);
		} while (flag == 0);
		
		//for (int i = 0; i < 6; i++)
		//{
		//	for (int j = 0; j < 7; j++)
		//	{
		//		printf("[%d] ", uredeniParovi[i][j]);
		//	}
		//	printf("\n");
		//}

		int sizep = sizeof(uredeniParovi)/sizeof(int);
		int sizeN = sizeof(paroviZaProvjeru) / sizeof(int);
		short winer = gameLoopv_2(p1, pok1, p2, pok2, uredeniParovi,sizep,paroviZaProvjeru,sizeN); //(p1, p2, pok1, pok2);
		if (winer == 1) {
			printf("\n\n\n\t\t\t!!!POBJEDNIK!!!\n\n\n");
			printf("\n\t\t\t   %s ", p1.nick);
			printf("\n\n\n\n\t\t\t!!!POBJEDNIK!!!\n");
			printf("\n\t\t\t     GG WP\n\n");
		}
		if (winer == 2) {
			printf("\n\n\n\t\t\t!!!POBJEDNIK!!!\n\n\n");
			printf("\n\t\t\t   %s ", p2.nick);
			printf("\n\n\n\n\t\t\t!!!POBJEDNIK!!!\n");
			printf("\n\t\t\t     GG WP\n\n");
		}
			/*/textcolor(2,1);
			
			return 1;
 		}

		/*else {
			printf("\n\t%s je pobijedio rundu!\n",p2.nick);
			printf("Cestitke!!");
		}*/
		
		printf("\n");
		//setPlayers(pBoard, boardSize,pok1,pok2); // i print matrice novo nastale
		
		//printf("\n\n\nStisni bilo koju tipku za bacanje...\n");// Gumb za igranje mini igre
		//ocistiKonzolu();
		//setPlayers(pBoard, boardSize,pok1, pok2);
		//getch();
		
//		free(pBoard);*/

		// Basic AI za bota
		// Gumb za bacacnje kocke
		// Refresh matrice da se vidi promjema nakon bacanja
		// Randomizira zmije i ljestve
		// Tumač znakova ispod matrice za elemente na matrici
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

