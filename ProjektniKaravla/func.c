
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
#include <math.h>
#include <time.h>
#include <conio.h>


#define BOARDX  10 // length of text line
#define BOARDY  10
#define BOARDW  (BOARDX*2)

int board[BOARDY][BOARDW + 1];          // allow for string terminator

char siguranUnosCHARa(char* printfMess) {
	char meta;
	char c;
	//printf("%s",printfMess);
	do
	{
		printf("%s", printfMess);
	} while (((scanf("%c%c", &meta, &c) != 2 || c != '\n') && clean_stdin()));
	return meta;
}
int siguranUnosINTa(char* printfMess, int dGran, int gGran) {
	int targ = 0;
	char c;
	if (dGran == 0 && gGran == 0) {
		printf("%s", printfMess);
	}
	else {
		printf("Unesi izbor %d-%d: ", dGran, gGran);
	}
	while (((scanf("%d%c", &targ, &c) != 2 || c != '\n') && clean_stdin()))
	{
		printf("%s", printfMess);
	}
	return targ;
}

int clean_stdin() {
	while (getchar() != '\n');
	return 1;
}
short gameLoopv_2(PLAYER_IG p1, PLAYER_IG* pok1, PLAYER_IG p2, PLAYER_IG* pok2, int* UpParovi, int UpPsize, int* zaProvjeru, int ZaPsize) {//(PLAYER_IG p1, PLAYER_IG p2, PLAYER_IG* pok1, PLAYER_IG* pok2)
	short win = 1, naRedu = 0;//													ima sve vrijednosti		samo x i y
	//(int*)uredeniParovi,sizeUrPx,sizeUrPy,,,,,|(int*)paroviZaProvjeru,sizePzPx,sizePzPy
	if (pok1->boardPositionX == 9 && pok1->boardPositionY == 9) { //|| pok2->boardPositionX == 10 && pok2->boardPositionY == 10) {
		return 1;
	}
	else if (pok2->boardPositionX == 9 && pok2->boardPositionY == 9) {
		return 2;
	}
	else {
		int kocka;
		place_playersAnal(pok1, pok2, (int*)UpParovi, UpPsize);
		while (win != 0) {

			if (naRedu == 0) {
				naRedu = rand() % 2 + 1;
			}
			if (naRedu % 2 == 0) {
				naRedu++;
			}
			else {
				naRedu++;

			}

			kocka = bacanje();
			if ((naRedu + 1) % 2 == 0) {
				printf("\n\n\t Vrijednost kocke (igrac): %d \n\n", kocka);//igrac baca
				primjeniKocku(kocka, pok1, zaProvjeru, ZaPsize);
			}
			else {
				printf("\n\n\t Vrijednost kocke (bot): %d \n\n", kocka);//bot baca
				primjeniKocku(kocka, pok2, zaProvjeru, ZaPsize);
			}

			place_playersAnal(pok1, pok2, (int*)UpParovi, UpPsize);
			if (pok1->boardPositionX == 9 && pok1->boardPositionY == 9)
				win = 0;
			if (pok2->boardPositionX == 9 && pok2->boardPositionY == 9)
				win = 0;

		}
		if (pok1->boardPositionX == 9 && pok1->boardPositionY == 9) {
			return 1;
		}
		else if (pok2->boardPositionX == 9 && pok2->boardPositionY == 9) {
			return 2;
		}

	}
	return 3;
}
int rndNum(int DG, int GG) {
	return round((DG + (float)rand() / RAND_MAX * (GG - DG)));
}
int checkingUniqness(int* arr, const int io, int jo) {//,6,4

	int newArr[12] = { 0 }, k = 0;
	for (int i = 0; i < (io * 2); i += 2) {// do 6  //do (4) 0 1 2 3
		{
			int j = 0;
			newArr[i] = (*(arr + k * 4 + j) * 10) + (*(arr + k * 4 + j + 1));
			newArr[i + 1] = (*(arr + k * 4 + j + 2) * 10) + (*(arr + k * 4 + j + 3));
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
void primjeniKocku(int brojKocke, PLAYER_IG* p, int* polje, int size) {
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



	if (p->boardPositionY > broj || p->boardPositionY == broj && p->boardPositionX == broj) {
		p->boardPositionX = broj;
		p->boardPositionY = broj;
	}
}
void place_playersAnal(PLAYER_IG* p1, PLAYER_IG* p2, int* arr, int arrSize) {
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
			int indx[] = { 0,1,2,3,4,5,6 };

			int j = 0;
			int i = 0;
			int s0 = *(arr + (indx[i] * 7) + j);
			int s1 = *(arr + (indx[i] * 7) + j + 1);
			int s2 = *(arr + (indx[i] * 7) + j + 2);
			int s3 = *(arr + (indx[i] * 7) + j + 3);
			int s4 = *(arr + (indx[i] * 7) + j + 4);
			int s5 = *(arr + (indx[i] * 7) + j + 5);// j 0 1 2 3 4 5
			int s6 = *(arr + (indx[i] * 7) + j + 6);
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
				printf("%s%s ", p1->tag, p1->tag);
				textColorReset();
				printf("| ");
			}
			else if ((m - 1) == p2->boardPositionX && n == p2->boardPositionY) {
				textcolor(4, 1);
				printf("%s%s ", p2->tag, p2->tag);
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
				s6 = *(arr + (indx[i] * 7) + j + 6), (m - 1) == s2 && n == s3) {//0,1 //[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR]
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

	printf("\t     ");
	for (x = 10; x > 0; x--)//zadnji red brojke
		printf("%2d   ", x);
	printf("\n");
}
void textColorReset() {
	printf("\033[0m");
}
void textcolor(int color, int bold) {
	switch (color) {
	case 1:
		if (bold == 0) {
			printf("\033[0;30m");
		}
		else {
			printf("\033[1;30m");
		}
		break;
	case 2:
		if (bold == 0) {
			printf("\033[0;31m");
		}
		else {
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

int ispisiLeaderboard(int z) {
	FILE* fp = NULL;
	if (z == 0 || (fp = fopen("dat.txt", "r")) == NULL) {
		printf("\nNema igraca, prvo kreirajte igrace odabirom opcije 2.\n\n");
		return -1;
	}
	else {
		FILE* fp = NULL;
		fp = fopen("dat.txt", "r");
		if (fp == NULL) {
			perror("greska u otvaranju");
			exit(EXIT_FAILURE);
		}
		PLAYER_IG* ply = NULL;
		ply = (PLAYER_IG*)calloc(z, sizeof(PLAYER_IG));
		if (ply == NULL) {
			perror("greska");
			exit(EXIT_FAILURE);

		}
		printf("\n\n\n");
		printf("\n\t|---------------------------------------------------------------------------------------------|\n");
		printf("\t|               |            |                       |                  |                     |\n");
		printf("\t|      RANK     |     ID     |      Nick Igraca      |   Broj Pobjeda   |    Oznaka Igraca    |\n");
		printf("\t|               |            |                       |                  |                     |\n");
		printf("\t|---------------------------------------------------------------------------------------------|\n");
		for (int i = 0; i < z; i++) {

			fscanf(fp, "%d %d %s %s %d", &(ply + i)->ID, &(ply + i)->rank, (ply + i)->nick, (ply + i)->tag, &(ply + i)->winNum);

			printf("\n\t        %d             %d             ", (ply + i)->rank, (ply + i)->ID);
			int duljinaNicka = 0;
			char* nick = (ply + i)->nick;


			for (int j = 0; j < strlen(nick); j++) {
				if (*(nick + j) != ' ') {
					duljinaNicka++;
				}
			}
			switch (duljinaNicka) {
			case 1:
				printf("%s             ", (ply + i)->nick);
				break;
			case 2:
				printf("%s            ", (ply + i)->nick);
				break;
			case 3:
				printf("%s           ", (ply + i)->nick);
				break;
			case 4:
				printf("%s          ", (ply + i)->nick);
				break;
			case 5:
				printf("%s         ", (ply + i)->nick);
				break;
			case 6:
				printf("%s        ", (ply + i)->nick);
				break;
			case 7:
				printf("%s       ", (ply + i)->nick);
				break;
			case 8:
				printf("%s      ", (ply + i)->nick);
				break;
			case 9:
				printf("%s     ", (ply + i)->nick);
				break;
			case 10:
				printf("%s    ", (ply + i)->nick);
				break;
			case 11:
				printf("%s   ", (ply + i)->nick);
				break;
			case 12:
				printf("%s  ", (ply + i)->nick);
				break;
			case 13:
				printf("%s ", (ply + i)->nick);
				break;
			case 14:
				printf("%s", (ply + i)->nick);
				break;

			default:
				printf("%s", (ply + i)->nick);
				break;
			}
			printf("               %d                  %s        \n", (ply + i)->winNum, (ply + i)->tag);
			printf("\t|---------------------------------------------------------------------------------------------|\n");

		}
		free(ply);
		fclose(fp);
		return 1;
	}
}
PLAYER_IG trazenjeID(int k, int trazeniID) {
	FILE* fp = NULL;
	if (k == 0 || (fp = fopen("dat.txt", "r")) == NULL) {
		printf("\n\tNema igraca, prvo kreirajte igrace odabirom opcije 2.\n\n");
		PLAYER_IG player;
		player.rank = -1;
		return player;
	}
	else {

		PLAYER_IG* ply = NULL;
		ply = (PLAYER_IG*)calloc(k, sizeof(PLAYER_IG));
		if (ply == NULL) {
			perror("greska");
			exit(EXIT_FAILURE);
		}
		int provjera = 0;
		int i;
		for (i = 0; i < k; i++) {

			fscanf(fp, "%d %d %s %s %d", &(ply + i)->ID, &(ply + i)->rank, (ply + i)->nick, (ply + i)->tag, &(ply + i)->winNum);
			if (trazeniID == (ply + i)->ID) {
				provjera = 1;
				break;

			}
		}

		PLAYER_IG player;
		if (provjera == 1) {
			player.ID = (ply + i)->ID;
			player.rank = (ply + i)->rank;
			strcpy(player.nick, (ply + i)->nick);
			strcpy(player.tag, (ply + i)->tag);
			player.winNum = (ply + i)->winNum;

			printf("\n\tIgrac pronaden!\n\nID: %d, Rank: %d, Nick: %s, Tag: %s, Total Wins: %d\n\n", (ply + i)->ID, (ply + i)->rank, (ply + i)->nick, (ply + i)->tag, (ply + i)->winNum);
		}
		else {
			printf("\n\tIgrac s trazenim ID-em nije naden!\n");
			player.rank = -1;
		}
		free(ply);
		fclose(fp);
		return player;

	}
}
int kreirajPlayera(void) {

	FILE* fp = NULL;
	PLAYER_IG* ply = NULL;
	int k = brojPlayera();
	ply = (PLAYER_IG*)calloc(k + 1, sizeof(PLAYER_IG));
	if (ply == NULL) {
		perror("greska s playerom");
		exit(EXIT_FAILURE);
	}
	fp = fopen("dat.txt", "a");
	if (fp == NULL) {
		perror("greska s datotekom");
		exit(EXIT_FAILURE);
	}
	//--------------------------------------------------------------Kreiranje datoteke i deklariranje strukture

	int provjeraPly;
	int provjeraID1;
	int provjeraTag1;
	//k = brojPlayera();
	printf("\tUnesite nadimak za svog igraca: ");
	do {
		scanf("%14s", ply->nick);

		provjeraPly = provjeraNick(k, ply->nick);
		if (provjeraPly == 1) {
			printf("\n\tOvo korisnicko ime se vec koristi, pokusajte ponovo: ");
		}
	} while (provjeraPly != 0); // -------------------------------------------------------------------NICK

	//| RANK(num) | ID(num) | Nick Igraca(string) | Broj Pobjeda(num) | Oznaka Igraca(char) |

	//printf("\n\tUnesite oznaku za svog igraca: ");
	do {
		do {
			*(ply->tag) = siguranUnosCHARa("\n\tUnesite oznaku za svog igraca: ");
			provjeraTag1 = provjeraTaga(k, ply->tag);
			if (provjeraTag1)
			{
				printf("\tTa oznaka vec postoji..\n\n");
				printf("\tPokusaj ponovno..  ");
				*(ply->tag) = siguranUnosCHARa("\n\tUnesite oznaku za svog igraca: ");
				provjeraTag1 = provjeraTaga(k, ply->tag);
			}

		} while (provjeraTag1 == 1);
		if (ply->tag >= 48 && ply->tag <= 57 || ply->tag == 38 || ply->tag == 66) {//
			printf("\tNije moguce unijeti 0-9, & ili B kao korisnicku oznaku..\n\n");
			printf("\tPokusaj ponovno..  ");
		}// 38 = &, 0-9 = 48-57
	} while (ply->tag >= 48 && ply->tag <= 57 || (ply->tag) == 38 || (ply->tag) == 66); // ---------------------------------TAG


	do {
		ply->ID = siguranUnosINTa("\n\tUpisite svoj ID: ", 0, 0);
		provjeraID1 = provjeraID(k, ply->ID);
		if (provjeraID1 == 1) {
			printf("\tOvaj ID je zauzet, pokusajte ponovo: ");
		}
	} while (provjeraID1 != 0);// --------------------------------------------------------------------ID

	k = brojPlayera();
	ply->rank = k + 1;
	ply->winNum = 0;
	fprintf(fp, "%d %d %s %s %d ", ply->ID, ply->rank, ply->nick, ply->tag, ply->winNum);
	printf("\n\tUspjesno kreiranje igraca.\n");
	free(ply);
	fclose(fp);
	return 1;

}
int provjeraNick(int k, char* playerNick) {
	FILE* fp = NULL;
	if (k == 0 || (fp = fopen("dat.txt", "r")) == NULL) {
	}
	else {

		PLAYER_IG* ply = NULL;
		ply = (PLAYER_IG*)calloc(k, sizeof(PLAYER_IG));
		if (ply == NULL) {
			perror("greska");
			exit(EXIT_FAILURE);
		}
		int provjeraNicka = 0;
		for (int i = 0; i < k; i++) {
			//ply->ID, ply->rank, ply->nick,  ply->tag, ply->winNum
			fscanf(fp, "%d %d %s %s %d", &(ply + i)->ID, &(ply + i)->rank, (ply + i)->nick, (ply + i)->tag, &(ply + i)->winNum);
			//printf("Compare: %d\n",strcmp(playerNick, (ply + i)->nick)); testiranje
			if ((!strcmp(playerNick, (ply + i)->nick))) {
				provjeraNicka = 1;
				break;
			}

		}
		fclose(fp);
		free(ply);
		return provjeraNicka;
	}
	return 0;
}
int provjeraID(int k, int ID) {
	FILE* fp = NULL;
	if (k == 0 || (fp = fopen("dat.txt", "r")) == NULL) {
	}
	else {

		PLAYER_IG* ply = NULL;
		ply = (PLAYER_IG*)calloc(k, sizeof(PLAYER_IG));
		if (ply == NULL) {
			perror("greska");
			exit(EXIT_FAILURE);
		}
		int provjeraIDa = 0;

		for (int i = 0; i < k; i++) {
			//ply->ID, ply->rank, ply->nick,  ply->tag, ply->winNum
			fscanf(fp, "%d %d %s %s %d", &(ply + i)->ID, &(ply + i)->rank, (ply + i)->nick, (ply + i)->tag, &(ply + i)->winNum);

			if ((ID == (ply + i)->ID)) {
				provjeraIDa = 1;
				break;
			}

		}
		fclose(fp);
		free(ply);
		return provjeraIDa;
	}
}
int provjeraTaga(int k, char* tag) {
	FILE* fp = NULL;
	if (k == 0 || (fp = fopen("dat.txt", "r")) == NULL) {
	}
	else {

		PLAYER_IG* ply = NULL;
		ply = (PLAYER_IG*)calloc(k, sizeof(PLAYER_IG));
		if (ply == NULL) {
			perror("greska");
			exit(EXIT_FAILURE);
		}
		int provjeraIDa = 0;

		for (int i = 0; i < k; i++) {
			//ply->ID, ply->rank, ply->nick,  ply->tag, ply->winNum
			fscanf(fp, "%d %d %s %s %d", &(ply + i)->ID, &(ply + i)->rank, (ply + i)->nick, (ply + i)->tag, &(ply + i)->winNum);
			if ((!strcmp(tag, (ply + i)->tag))) {
				provjeraIDa = 1;
				break;
			}

		}
		fclose(fp);
		free(ply);
		return provjeraIDa;
	}return 0;
}
int brojPlayera(void) {//vec spremljenih u datoteci

	FILE* fp = NULL;
	if ((fp = fopen("dat.txt", "r")) == NULL) {
		return 0;
	}
	else {
		int i, br = 0;
		int koef = 50;// chars in one file segment
		do {
			char* read = calloc(koef, sizeof(char));
			if (read == NULL) {
				exit(EXIT_FAILURE);
			}
			fgets(read, koef, fp);
			for (int i = 0; i < koef; i++) {
				if (*(read + i) == ' ') {
					br++;
				}
			}
			if (feof(fp)) {
				break;
			}
			else {
				koef += 50;
			}
			free(read);
		} while (1);
		fclose(fp);
		return br / 5;
	}
}
void obirisiPlayera(int z) {
	FILE* fp = NULL;

	if ((fp = fopen("dat.txt", "r")) == NULL || z == 0) {
		printf("\n\tNema igraca, prvo kreirajte igrace odabirom opcije 2.\n\n");

	}
	else {

		if (ispisiLeaderboard(z) == -1) {
			printf("\n\tNema igraca, prvo kreirajte igrace odabirom opcije 2.\n\n");
		}
		else {
			PLAYER_IG* ply = NULL;
			ply = (PLAYER_IG*)calloc(z, sizeof(PLAYER_IG));
			if (ply == NULL) {
				perror("greska");
				exit(EXIT_FAILURE);
			}

			int PlyID = siguranUnosINTa("\tUnesi ID igraca kojega se zeli obrisati: ", 0, 0);
			int provjera = 0, i;
			fp = fopen("dat.txt", "r");
			for (i = 0; i < z; i++) {

				fscanf(fp, "%d %d %s %s %d", &(ply + i)->ID, &(ply + i)->rank, (ply + i)->nick, (ply + i)->tag, &(ply + i)->winNum);
			}
			fclose(fp);
			fp = fopen("dat.txt", "w");
			for (i = 0; i < z; i++) {
				if (PlyID != (ply + i)->ID) {
					fprintf(fp, "%d %d %s %s %d ", (ply + i)->ID, (ply + i)->rank, (ply + i)->nick, (ply + i)->tag, (ply + i)->winNum);
				}
			}
			printf("\n\tIgrac uspjesno obrisan!\n");
			fclose(fp);
			free(ply);
		}
	}
}