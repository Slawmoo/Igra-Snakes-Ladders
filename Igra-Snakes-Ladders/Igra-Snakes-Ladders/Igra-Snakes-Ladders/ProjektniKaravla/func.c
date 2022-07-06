#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
#include <math.h>
#include <time.h>
#include <conio.h>

//static int brojClanova = 0;

//Definicije

#define BOARDX  10 // length of text line
#define BOARDY  10
#define BOARDW  (BOARDX*2)

int board[BOARDY][BOARDW+1];          // allow for string terminator



void start_board(void)
{
	int y, x,n=9;												   //------------------------------------------
	printf("\n\t   ---------------------------------------------------\n"); //__________________________________________
	for (y = BOARDY; y > 0; y--) {
		printf("\t%-2d | ", y);
		for (int m = 9; m >= 0; m--) {
			if (m == 0 && n == 0)// m = x os, n= y os
			{
				textcolor(4, 1);
				printf("&& ");
				textColorReset();
				printf("|");
				
			}
			else {
				printf("%d%d | ", n, m);
			}
		}
		n--;
		printf("\n");
		if (y != 1)
		{
			printf("\t   |-------------------------------------------------|\n");
		}
		
	}
	printf("\t   ");
	for (x = 0; x < BOARDX; x++) { // predzadnji red crte
		if (x == 0) {
			printf("|");
		}
		printf("----");
		if (x == 9) {
			printf("---------|");
		}
	}
	printf("\n");

	printf("\t   | ");
	for (x = 10; x > 0; x--)//zadnji red brojke
		printf("%2d | ", x);
	printf("\n");
}

short gameLoopv_2(PLAYER_IG p1, PLAYER_IG* pok1, PLAYER_IG p2, PLAYER_IG* pok2, int* polje,int size,int * zaProvjeru,int sizeProv) {//(PLAYER_IG p1, PLAYER_IG p2, PLAYER_IG* pok1, PLAYER_IG* pok2)
	short win = 1, naRedu = 0;//													ima sve vrijednosti		samo x i y
	
	if (pok1->boardPositionX == 9 && pok1->boardPositionY == 9) { //|| pok2->boardPositionX == 10 && pok2->boardPositionY == 10) {
		return 1;
	}
	else if (pok2->boardPositionX == 9 && pok2->boardPositionY == 9){
		return 2;
	}
	else {
		int kocka;
		while (win != 0) {
			if (naRedu == 0) {
				naRedu = rand() % 2 + 1;
			}
			if (naRedu % 2 == 0) {
				naRedu++;
				//rezMini = 2;
				//rezMini = miniGame(p2);// Mini igra pogadjanje (0-9)
			}
			else {
				naRedu++;
				//rezMini = 3;
				//rezMini = miniGame(p1);// Mini igra pogadjanje (0-9)
			}
			/*if (rezMini == 69) {
				//free(pBoard);
				exit(1);
			}
			//if (rezMini == 2)//prvi player mini dobio game
			 {*/
			kocka = bacanje();
			printf("\n\n\t1p Kocka: %d \n\n", kocka);
			if ((naRedu + 1) % 2 == 0) {
				primjeniKocku(kocka, pok1, zaProvjeru, sizeProv);
			}
			else {
				printf("\n2p Kocka: %d ", kocka);
				primjeniKocku(kocka, pok2, zaProvjeru, sizeProv);
			}
			/* }
			else {//drugi player dobio mini game
					kocka = bacanje();
					printf("\n(2p)Kocka: %d ", kocka);
					if (naRedu % 2 == 0) {
						primjeniKocku(kocka, pok1);
					}
					else {
						primjeniKocku(kocka, pok2);
					}
				}*/
				//ocistiKonzolu();*/
				//place_players(pok1, );
			place_playersAnal(pok1, pok2, polje, size);
			if (pok1->boardPositionX == 9 && pok1->boardPositionY == 9)
				win = 0;
			if (pok2->boardPositionX == 9 && pok2->boardPositionY == 9)
				win = 0;
			//ocistiKonzolu();
			//setPlayers(pBoard, pok1, pok2);
		}
		if (pok1->boardPositionX == 9 && pok1->boardPositionY == 9) {
			return 1;
		}
		else if (pok2->boardPositionX == 9 && pok2->boardPositionY == 9) {
			return 2;
		}
	}
}
/*int testVrijednosti(int m, int n, int* locOfLadSnakeFormatedY, int* locOfLadSnakeFormatedX,int size, int* POKtestVrijednostiY, int* POKtestVrijednostiBold, int* POKtestVrijednostiBoja, int* POKtestVrijednostiX,int* boje) {
	for (int i = 0; i < size; i++)
	{
		if (((m - 1) == *(locOfLadSnakeFormatedX + i)) && (n == *(locOfLadSnakeFormatedY + i))) {
			POKtestVrijednostiX = locOfLadSnakeFormatedX + i;
			POKtestVrijednostiY = locOfLadSnakeFormatedY + i;
			POKtestVrijednostiBoja = boje + (i / 2);
			if (i % 2 == 1) {
				*POKtestVrijednostiBold = 1;//bold 1
			}
			else {
				*POKtestVrijednostiBold = 0;//bold 0
			}
			return 1;
		}		
	}
	return 0;
}*/
int rndNum(DG,GG) {
	return (DG + (float)rand() / RAND_MAX * (GG - DG));
}
int checkingUniqness(int* arr, int io, int jo) {//,6,4
	
	int newArr[12] = {0},k=0;
	for (int i = 0; i < (io*2); i+=2) {// do 6  //do (4) 0 1 2 3
		{ 
			int j = 0;
			newArr[i] =   (*(arr + k * 4 + j) * 10) + (*(arr + k * 4 + j+1));
			newArr[i+1] = (*(arr + k * 4 + j+2) * 10) + (*(arr + k * 4 + j+3));
			k++;
		}
	}
/*	printf("Novo nastalo polje \n");
	for (int i = 0; i < 12; i++) {
		printf("[%d] ", newArr[i]);//*(q + i*co + j)
		if (i % 2 == 1) {
			printf("\n");
		}
	}printf("\n");
	
	printf("Pocetno polje \n");
	for (int i = 0; i < io; i++) {
		for (int j = 0; j < jo; j++) {
			printf("[%d] ", *(arr + i * jo + j));//*(q + i*co + j)
		}
		printf("\n");
	}

	printf("\n"); printf("\n");
	printf("\n");*/
	int x = isUniqueArray(newArr, 12);
	return x;
}
int isUniqueArray(int* polje, int len) {

	int i;
	int num_set[100] = { 0 };
	int val;

	for (i = 0; i < len; i++) {
		val = *(polje + i);

		if (num_set[val] != 0)
			return 0;

		num_set[val] = 1;
	}

	return 1; //This returns 1 if the string is unique
}
int bacanje() {
	return ((rand() % 6) + 1);
}
void primjeniKocku(int brojKocke, PLAYER_IG* p,int * polje, int size) {
	int broj = 9;
	p->boardPositionX += brojKocke;
	if (p->boardPositionX >= broj && p->boardPositionY >= broj) {
		p->boardPositionX = broj;
		p->boardPositionY = broj;
	}
	if (p->boardPositionX > broj) // prijelaz u visi red (y) i reset na desnu stranu (x)
	{
		p->boardPositionX -= broj + 1;
		p->boardPositionY++;
	}
	int indx[] = { 0,1,2,3,4,5 };
	// djelovanje zmijajaaaa
	for (int i = 0; i < 6; i++)
	{
		switch (i)
			{
			case 0:
				if (p->boardPositionX == *(polje + (indx[i] * 4) + 0) && p->boardPositionY == *(polje + (indx[i] * 4) + 1))//[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				{
					p->boardPositionX = *(polje + (indx[i] * 4) + 2);
					p->boardPositionY = *(polje + (indx[i] * 4) + 3);
				}
				break;
			case 1:
				if (p->boardPositionX == *(polje + (indx[i] * 4) + 0) && p->boardPositionY == *(polje + (indx[i] * 4) + 1))//[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				{
					p->boardPositionX = *(polje + (indx[i] * 4) + 2);
					p->boardPositionY = *(polje + (indx[i] * 4) + 3);
				}
				break;
			case 2:
				if (p->boardPositionX == *(polje + (indx[i] * 4) + 0) && p->boardPositionY == *(polje + (indx[i] * 4) + 1))//[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				{
					p->boardPositionX = *(polje + (indx[i] * 4) + 2);
					p->boardPositionY = *(polje + (indx[i] * 4) + 3);
				}
				break;
			case 3:
				if (p->boardPositionX == *(polje + (indx[i] * 4) + 0) && p->boardPositionY == *(polje + (indx[i] * 4) + 1))//[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				{
					p->boardPositionX = *(polje + (indx[i] * 4) + 2);
					p->boardPositionY = *(polje + (indx[i] * 4) + 3);
				}
				break;
			case 4:
				if (p->boardPositionX == *(polje + (indx[i] * 4) + 0) && p->boardPositionY == *(polje + (indx[i] * 4) + 1))//[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				{
					p->boardPositionX = *(polje + (indx[i] * 4) + 2);
					p->boardPositionY = *(polje + (indx[i] * 4) + 3);
				}
				break;
			case 5:
				if (p->boardPositionX == *(polje + (indx[i] * 4) + 0) && p->boardPositionY == *(polje + (indx[i] * 4) + 1))//[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				{
					p->boardPositionX = *(polje + (indx[i] * 4) + 2);
					p->boardPositionY = *(polje + (indx[i] * 4) + 3);
				}
				break;
			default:
				break;
		}
	}
	
	

	if (p->boardPositionY > broj || p->boardPositionY == broj && p->boardPositionX == broj){
		p->boardPositionX = broj;
		p->boardPositionY = broj;
	}
}
void place_playersAnal(PLAYER_IG* p1, PLAYER_IG* p2, int* arr, int size)//, PLAYER_IG* p2)
{
	int y, x, m, n = 9;
	printf("\n\t   ---------------------------------------------------\n");
		for (y = BOARDY; y > 0; y--) {
		printf("\t%-2d | ", y);
		for (m = 10; m > 0; m--) {// m = x os, n= y os
			/*if (p1->boardPositionX == p2->boardPositionX && p1->boardPositionY == p2->boardPositionY)
			{
				textcolor(7, 1);
				printf("&&  ");
				textColorReset();
			}*/
			int indx[] = { 0,1,2,3,4,5,6};
			
			//*(arr + (i*max(j)) +j)
			int j =0;
			int i=0;
			int s0 = *(arr + (indx[i] * 7) + j);
			int s1 = *(arr + (indx[i] * 7) + j+1);
			int s2 = *(arr + (indx[i] * 7) + j+2);
			int s3 = *(arr + (indx[i] * 7) + j+3);
			int s4 = *(arr + (indx[i] * 7) + j+4);
			int s5 = *(arr + (indx[i] * 7) + j+5);// j 0 1 2 3 4 5
			int s6 = *(arr + (indx[i] * 7) + j+6);
			/// --------------------------------
			if ((m - 1) == (p1->boardPositionX) && (m - 1) == p2->boardPositionX && n == p2->boardPositionY && n == p1->boardPositionY)// m = x os, n= y os
			{
				textcolor(4, 1);
				printf("&& ");
				textColorReset();
				printf("| ");
			}
			else if ((m - 1) == p1->boardPositionX && n == p1->boardPositionY) {
				textcolor(5, 1);
				printf("%c%c ", p1->tag, p1->tag);
				textColorReset();
				printf("| ");
			}else if((m - 1) == p2->boardPositionX && n == p2->boardPositionY) {
				textcolor(4, 1);
				printf("%c%c ", p2->tag, p2->tag);
				textColorReset();
				printf("| ");
			}
			else if (i = 0,
				s0 = *(arr + (indx[i] * 7) + j),
				s1 = *(arr + (indx[i] * 7) + j + 1),
				s2 = *(arr + (indx[i] * 7) + j + 2),
				s3 = *(arr + (indx[i] * 7) + j + 3),
				s4 = *(arr + (indx[i] * 7) + j + 4),
				s5 = *(arr + (indx[i] * 7) + j + 5),
				s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s0 && n == s1) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				textcolor(s4, s5);//4,5
				printf("%d%d ", s1, s0);//1,0
				textColorReset(); printf("| ");
			}
			else if (i = 0,
				 s0 = *(arr + (indx[i] * 7) + j),
				 s1 = *(arr + (indx[i] * 7) + j + 1),
				 s2 = *(arr + (indx[i] * 7) + j + 2),
				 s3 = *(arr + (indx[i] * 7) + j + 3),
				 s4 = *(arr + (indx[i] * 7) + j + 4),
				 s5 = *(arr + (indx[i] * 7) + j + 5),
				 s6 = *(arr + (indx[i] * 7) + j + 6),(m - 1) == s2 && n == s3) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				textcolor(s4, s6);//4,5
				printf("%d%d ", s3, s2);//1,0
				textColorReset(); printf("| ");
			}//////////////////////
			else if (i = 1,
				s0 = *(arr + (indx[i] * 7) + j),
				s1 = *(arr + (indx[i] * 7) + j + 1),
				s2 = *(arr + (indx[i] * 7) + j + 2),
				s3 = *(arr + (indx[i] * 7) + j + 3),
				s4 = *(arr + (indx[i] * 7) + j + 4),
				s5 = *(arr + (indx[i] * 7) + j + 5),
				s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s0 && n == s1) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				textcolor(s4, s5);//4,5
				printf("%d%d ", s1, s0);//1,0
				textColorReset(); printf("| ");
			}
			else if (i = 1,
				s0 = *(arr + (indx[i] * 7) + j),
				s1 = *(arr + (indx[i] * 7) + j + 1),
				s2 = *(arr + (indx[i] * 7) + j + 2),
				s3 = *(arr + (indx[i] * 7) + j + 3),
				s4 = *(arr + (indx[i] * 7) + j + 4),
				s5 = *(arr + (indx[i] * 7) + j + 5),
				s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s2 && n == s3) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				textcolor(s4, s6);//4,5
				printf("%d%d ", s3, s2);//1,0
				textColorReset(); printf("| ");
			}
			else if (i = 2,
				s0 = *(arr + (indx[i] * 7) + j),
				s1 = *(arr + (indx[i] * 7) + j + 1),
				s2 = *(arr + (indx[i] * 7) + j + 2),
				s3 = *(arr + (indx[i] * 7) + j + 3),
				s4 = *(arr + (indx[i] * 7) + j + 4),
				s5 = *(arr + (indx[i] * 7) + j + 5),
				s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s0 && n == s1) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				textcolor(s4, s5);//4,5
				printf("%d%d ", s1, s0);//1,0
				textColorReset(); printf("| ");
			}
			else if (i = 2,
				s0 = *(arr + (indx[i] * 7) + j),
				s1 = *(arr + (indx[i] * 7) + j + 1),
				s2 = *(arr + (indx[i] * 7) + j + 2),
				s3 = *(arr + (indx[i] * 7) + j + 3),
				s4 = *(arr + (indx[i] * 7) + j + 4),
				s5 = *(arr + (indx[i] * 7) + j + 5),
				s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s2 && n == s3) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				textcolor(s4, s6);//4,5
				printf("%d%d ", s3, s2);//1,0
				textColorReset(); printf("| ");
			}
			else if (i = 3,
				s0 = *(arr + (indx[i] * 7) + j),
				s1 = *(arr + (indx[i] * 7) + j + 1),
				s2 = *(arr + (indx[i] * 7) + j + 2),
				s3 = *(arr + (indx[i] * 7) + j + 3),
				s4 = *(arr + (indx[i] * 7) + j + 4),
				s5 = *(arr + (indx[i] * 7) + j + 5),
				s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s0 && n == s1) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				textcolor(s4, s5);//4,5
				printf("%d%d ", s1, s0);//1,0
				textColorReset(); printf("| ");
			}
			else if (i = 3,
				s0 = *(arr + (indx[i] * 7) + j),
				s1 = *(arr + (indx[i] * 7) + j + 1),
				s2 = *(arr + (indx[i] * 7) + j + 2),
				s3 = *(arr + (indx[i] * 7) + j + 3),
				s4 = *(arr + (indx[i] * 7) + j + 4),
				s5 = *(arr + (indx[i] * 7) + j + 5),
				s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s2 && n == s3) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				textcolor(s4, s6);//4,5
				printf("%d%d ", s3, s2);//1,0
				textColorReset(); printf("| ");
			}
			else if (i = 4,
				s0 = *(arr + (indx[i] * 7) + j),
				s1 = *(arr + (indx[i] * 7) + j + 1),
				s2 = *(arr + (indx[i] * 7) + j + 2),
				s3 = *(arr + (indx[i] * 7) + j + 3),
				s4 = *(arr + (indx[i] * 7) + j + 4),
				s5 = *(arr + (indx[i] * 7) + j + 5),
				s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s0 && n == s1) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				textcolor(s4, s5);//4,5
				printf("%d%d ", s1, s0);//1,0
				textColorReset(); printf("| ");
			}
			else if (i = 4,
				s0 = *(arr + (indx[i] * 7) + j),
				s1 = *(arr + (indx[i] * 7) + j + 1),
				s2 = *(arr + (indx[i] * 7) + j + 2),
				s3 = *(arr + (indx[i] * 7) + j + 3),
				s4 = *(arr + (indx[i] * 7) + j + 4),
				s5 = *(arr + (indx[i] * 7) + j + 5),
				s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s2 && n == s3) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
				textcolor(s4, s6);//4,5
				printf("%d%d ", s3, s2);//1,0
				textColorReset(); printf("| ");
			}
			else if (i = 5,
			s0 = *(arr + (indx[i] * 7) + j),
			s1 = *(arr + (indx[i] * 7) + j + 1),
			s2 = *(arr + (indx[i] * 7) + j + 2),
			s3 = *(arr + (indx[i] * 7) + j + 3),
			s4 = *(arr + (indx[i] * 7) + j + 4),
			s5 = *(arr + (indx[i] * 7) + j + 5),
			s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s0 && n == s1) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
			textcolor(s4, s5);//4,5
			printf("%d%d ", s1, s0);//1,0
			textColorReset(); printf("| ");
			}
			else if (i = 5,
			s0 = *(arr + (indx[i] * 7) + j),
			s1 = *(arr + (indx[i] * 7) + j + 1),
			s2 = *(arr + (indx[i] * 7) + j + 2),
			s3 = *(arr + (indx[i] * 7) + j + 3),
			s4 = *(arr + (indx[i] * 7) + j + 4),
			s5 = *(arr + (indx[i] * 7) + j + 5),
			s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s2 && n == s3) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
			textcolor(s4, s6);//4,5
			printf("%d%d ", s3, s2);//1,0
			textColorReset(); printf("| ");
			}
			else if (i = 6,
			s0 = *(arr + (indx[i] * 7) + j),
			s1 = *(arr + (indx[i] * 7) + j + 1),
			s2 = *(arr + (indx[i] * 7) + j + 2),
			s3 = *(arr + (indx[i] * 7) + j + 3),
			s4 = *(arr + (indx[i] * 7) + j + 4),
			s5 = *(arr + (indx[i] * 7) + j + 5),
			s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s0 && n == s1) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
			textcolor(s4, s5);//4,5
			printf("%d%d ", s1, s0);//1,0
			textColorReset(); printf("| ");
			}
			else if (i = 6,
			s0 = *(arr + (indx[i] * 7) + j),
			s1 = *(arr + (indx[i] * 7) + j + 1),
			s2 = *(arr + (indx[i] * 7) + j + 2),
			s3 = *(arr + (indx[i] * 7) + j + 3),
			s4 = *(arr + (indx[i] * 7) + j + 4),
			s5 = *(arr + (indx[i] * 7) + j + 5),
			s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s2 && n == s3) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
			textcolor(s4, s6);//4,5
			printf("%d%d  ", s3, s2);//1,0
			textColorReset();
			}
			else {
				printf("%d%d ", n, m - 1);
				textColorReset(); 
				printf("| ");
			}
		}
		n--;
		printf("\n");
		if (y != 1)
		{
			printf("\t   |-------------------------------------------------|\n");
		}

	}
	printf("\t   ");
	for (x = 0; x < BOARDX; x++) { // predzadnji red crte
		if (x == 0) {
			printf("|");
		}
		printf("----");
		if (x == 9) {
			printf("---------|");
		}
	}
	printf("\n");

	printf("\t   | ");
	for (x = 10; x > 0; x--)//zadnji red brojke
		printf("%2d | ", x);
	printf("\n");
}

void textColorReset() {
		printf("\033[0m");
	}
void textcolor(int color, int bold) {
		switch (color){
			case 1:
				if (bold == 0){
					printf("\033[0;30m");
				}else{
					printf("\033[1;30m");
				}
				break;
			case 2:
				if (bold == 0){
					printf("\033[0;31m");
				}else{
					printf("\033[1;31m");
				}
				break;
		case 3:
			if (bold == 0)
			{
				printf("\033[0;32m");
			}
			else
			{
				printf("\033[1;32m");
			}
		case 4:
			if (bold == 0) {
				printf("\033[0;33m");
			}
			else {
				printf("\033[1;33m");
			}break;
		case 5:
			if (bold == 0) {
				printf("\033[0;34m");
			}
			else {
				printf("\033[1;34m");
			}break;
		case 6:
			if (bold == 0) {
				printf("\033[0;35m");
			}
			else {
				printf("\033[1;35m");
			}break;
		case 7:
			if (bold == 0) {
				printf("\033[0;36m");
			}
			else {
				printf("\033[1;36m");
			}break;
		case 8:
			if (bold == 0) {
				printf("\033[0;37m");
			}
			else {
				printf("\033[1;37m");
			}
		default:
			printf("\033[0m");
			break;
		}
}
void ocistiKonzolu() {
	system("cls");
	printf("\n\n");
}
int izlazIzPrograma() {

	//free(board);
	printf("\nZelite li izaci iz programa ?");
	printf("\n\nUtipkajte \"y\" ako želite u suprotno utipkajte\"n\"!\n");
	char pot = _getch();
	//scanf("%1s", potvrda);
	if (pot == 'y') {
		return 0;
	}
	else {
		return 1;
	}
}

/*void empty_board(void)
{
	int y, x,br= 100;
	for (y = 0; y < BOARDY; y++) {
		for (x = 0; x < BOARDW; x++) {
			board[y][x] = br;
			br --;
		}
		board[y][x] = '\0';
	}
}*/

/*int miniGame(PLAYER_IG prviIgrac) {

	printf("\n\n\n\tMINI GAME\n\tHIGHER LOWER");
	printf("\n\nIgrac %s bira pocetni broj (0-9):\n\n",prviIgrac.nick);//ako igrac sluc izabere tocan broj ima 2 bacanja
	int selectNum=0;
	do {
		scanf("%d", &selectNum);
		if (selectNum < 1 || selectNum >9) {
			printf("Pogresan unos pokusaj ponovno: \n");
		}
	} while (selectNum < 1 || selectNum >9);
	int izbor[] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 };
	int sicNum = rand() % 10;
	printf("\n\t0, 1, 2, 3, 4, 5, 6, 7, 8, 9");
	printf("\n\nStartni broj je: %d", selectNum);
	if (selectNum == sicNum) {
		//Prvi igrac 2x bacanja
		return 1;
	}
	else {
		char c;
		do{
			printf("\nTrazeni broj je razlicit od %d\n", selectNum);
			printf("\nZa visi broj unesi \"h\" ili \"H\" za nizi \"l\" ili \"L\":\n\n");
			//scanf("%1[^\n]", potvrda);
			c = _getch();
			if (c == 'h' || c == 'H') {
				if (sicNum > selectNum) {
					return 3; // drugi igrac baca
				}
				else {
					return 2; // prvi igrac baca
				}
			}
			else if (c == 'l' || c == 'L') {
				if (sicNum < selectNum) {
					return 3;// drugi igrac baca
				}
				else {
					return 2;// prvi igrac baca
				}
			}
			else {
				printf("\nKrivi unos pokusaj ponovno...\n");
				//return 69;
			}
		} while (c == 'l' || c == 'L' || c == 'h' || c == 'H'); //(!(strcmp("l", c)) || !(strcmp("L", c)) || !(strcmp("h", c)) || !(strcmp("H", c)));
	}
	/*">x<"--------------------------------------------------------------------------//tu trea bit end komentara al testiro sam pa sam komentiro sve
	printf("\n\nUnesi \"stop\" za kraj igre\n");
	scanf("%1s", potvrda);
	if (strcmp("stop", potvrda)) {
		return 69;
	}
	return 0;
}*/

/*
		if (rezMini == 1)//prvi player dobio game x2
		{
			kocka = bacanje();
			printf("\n(x2)Kocka: %d ", kocka);
			if ((naRedu + 1) % 2 == 0) {
				primjeniKocku(kocka, pok1);//1 igrac
			}
			else {
				primjeniKocku(kocka, pok2);// 2 igrac
			}
			kocka = bacanje();
			printf("\n(x2)Kocka: %d ", kocka);
			if ((naRedu + 1) % 2 == 0) {
				primjeniKocku(kocka, pok1);//1 igrac
			}
			else {
				primjeniKocku(kocka, pok2);// 2 igrac
			}
		}*/

/*

// *****************************************

char* napraviBoard(int *bSize) {
	*bSize = 101;
	char* board = calloc(*bSize,sizeof(char));
	for (int i = 1; i < bSize; i++)
	{

	}
	ispisiBoard(board, bSize);
	return board;
}
void ispisiBoard(char* board, int* bSize) {
	printf("\t");
	short br = 1;
	for (int i = 101; i > 1; i--)
	{
		if (i == 101) {
			printf("%d  ", i - 1);
		}
		else if(i > 9){
			printf("%d   ", i - 1);
		}
		else {
			printf(" %d   ", i - 1);
		}
		if (br%10==0)
		{
			printf("\n\t");
		}
		br++;
	}
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
void setPlayers(char* pBoard, int bSize, PLAYER_IG* p1, PLAYER_IG* p2) {
	//ispisiBoard(pBoard);
	printf("\t");
	short br = 1;
	for (int i = bSize; i > 1; i--)
	{
		if (i == bSize) {
			if (p1->boardPosition == p2->boardPosition) {
				printf("%c  ", '&');
			}
			else if (i == p1->boardPosition) {
				printf("%c  ", p1->tag);
			}
			else if (i == p2->boardPosition) {
				printf("%c  ", p2->tag);
			}else {
				printf("%d  ", i - 1);
			}
		}
		else if (i > 9) {
			if (p1->boardPosition == p2->boardPosition) {
				printf("%c   ", '&');
			}
			else if (i == p1->boardPosition) {
				printf("%c   ", p1->tag);
			}
			else if (i == p2->boardPosition) {
				printf("%c   ", p2->tag);
			}
			else {
				printf("%d   ", i - 1);
			}
		}
		else {
			if (p1->boardPosition == p2->boardPosition) {
				printf(" %c   ", '&');
			}
			else if (i == p1->boardPosition) {
				printf(" %c   ", p1->tag);
			}
			else if (i == p2->boardPosition) {
				printf(" %c   ", p2->tag);
			}
			else {
				printf(" %d   ", i - 1);
			}
		}
		if (br % 10 == 0)
		{
			printf("\n\t");
		}
		br++;
	}
}





*/
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



