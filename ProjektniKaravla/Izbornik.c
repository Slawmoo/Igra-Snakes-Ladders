
#include "Header.h"

int izbornik() {
	int cond;
	printf("\t*********************************************************************************************\n");
	printf("\t*                                                                                           *\n");
	printf("\t*                                  SNAKESs & LADDERESs                                      *\n");
	printf("\t*                                                                                           *\n");
	printf("\t*********************************************************************************************\n");
	printf("\t*                                                                                           *\n");
	printf("\t*----------------------------------- GLAVNI IZBORNIK ---------------------------------------*\n");
	printf("\t*                                                                                           *\n");
	printf("\t*********************************************************************************************\n");
	printf("\t*                                   Izaberite opciju:                                       *\n");
	printf("\t*                                                                                           *\n");
	printf("\t*                                  1: Nova igra (JEDAN IGRAC)                               *\n");
	printf("\t*                                  2: Kreiranje novog igraca                                *\n");
	printf("\t*                                  3: Ljestvica svih igraca                                 *\n");
	printf("\t*                                  4: IZLAZ IZ IGRE !                                       *\n");
	printf("\t*                                                                                           *\n");
	printf("\t*                                                                                           *\n");
	printf("\t*********************************************************************************************\n");
	printf("\t                                   ");
	do {
		cond = siguranUnosINTa("Pokusajte ponovo:", 1, 4);
	} while (cond < 1 || cond>4);

	//ovo za pod izbornik ljestvica
	//printf("*\t\t\t    Opcija 4: Sortiranje zaposlenih.     \t\t\t    *\n");
	//printf("*\t\t\t    Opcija 5: Brisanje zaposlenog.       \t\t\t    *\n");
	//printf("*\t\t\t    Opcija 6: Trazenje po ID-u.          \t\t\t    *\n");
	int k;
	switch (cond) {
	case 1:
		k = brojPlayera();
		if (ispisiLeaderboard(k) == -1) {
			return 1;
		}
		int PlyID = siguranUnosINTa("\n\tUnesi ID igraca s kojime zelite igrati: ", 0, 0);
		PLAYER_IG p1 = trazenjeID(k, PlyID);
		if (p1.rank == -1) {
			printf("\n\tKreiraj igraca odabirom opcije 2 ili izaberi drugi ID.\n\n");
			return 1;
		}
		PLAYER_IG p2;
		PLAYER_IG* pok1 = &p1;
		PLAYER_IG* pok2 = &p2;
		p1.boardPositionX = 0;
		p1.boardPositionY = 0;
		strcpy(p1.tag, pok1->tag);
		strcpy(p2.nick, "Bot");
		p2.boardPositionX = 0;
		p2.boardPositionY = 0;
		strcpy(p2.tag, "B");
		//ocistiKonzolu();
		//printf("Player 1:\n\tNick: %s\n\tBoardPos: %d\n\tTag: %c",p1.nick, p1.boardPosition,p1.tag);// Ispis igraca
		//printf("\n\nPlayer 2:\n\tNick: %s\n\tBoardPos: %d\n\tTag: %c", p2.nick, p2.boardPosition, p2.tag);

		int DG = 0, GG = 9, flag = 0;

		int numOfLS = 6;
		int arrBoje[] = { 2,3,4,5,6,7,8 };//[i0][i1][i2][i3] [i4]  [i5]   [i6]
		int uredeniParovi[6][7];
		int paroviZaProvjeru[6][4];		//[Gx][Gy][Rx][Ry][Boja][BoldG][BoldR] 
		int sizeUp = numOfLS * 7;
		int sizeZp = numOfLS * 4;
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
			flag = checkingUniqness((int*)paroviZaProvjeru, numOfLS, 4);
		} while (flag == 0);

		short winer = gameLoopv_2(p1, pok1, p2, pok2, (int*)uredeniParovi, sizeUp, (int*)paroviZaProvjeru, sizeZp); //(p1, p2, pok1, pok2);
		if (winer == 1) {
			printf("\n\n\n\t\t\t!!!POBJEDNIK!!!\n\n\n");
			printf("\n\t\t\t      %s ", p1.nick);
			printf("\n\n\n\n\t\t\t!!!POBJEDNIK!!!\n");
			printf("\n\t\t\t     GG WP\n\n");
		}
		if (winer == 2) {
			printf("\n\n\n\t\t\t!!!POBJEDNIK!!!\n\n\n");
			printf("\n\t\t\t      %s ", p2.nick);
			printf("\n\n\n\n\t\t\t!!!POBJEDNIK!!!\n");
			printf("\n\t\t\t     GG WP\n\n");
		}

		printf("\n");

		break;


	case 2://Kreiraj igraca

		cond = kreirajPlayera();
		break;
	case 3:
		k = brojPlayera();
		if (ispisiLeaderboard(k) == -1) {
			return 1;
		}

		printf("\t*********************************************************************************************\n");
		printf("\t*                                                                                           *\n");
		printf("\t*-----------------------------------IZBORNIK TABLICE----------------------------------------*\n");
		printf("\t*                                                                                           *\n");
		printf("\t*********************************************************************************************\n");
		printf("\t*                                   Izaberite opciju:                                       *\n");
		printf("\t*                                                                                           *\n");
		printf("\t*                                  1: BRISANJE IGRACA PO ID-u                               *\n");
		printf("\t*                                  2: TRAZI IGRACA PO ID-u                                  *\n");
		printf("\t*                                  3: POVRATAK U GLAVNI IZBORNIK                            *\n");
		printf("\t*                                                                                           *\n");
		printf("\t*                                                                                           *\n");
		printf("\t*********************************************************************************************\n");
		printf("\t                                   ");
		int cond1;

		do {
			cond1 = siguranUnosINTa("Unesite izbor 1-3: ", 1, 3);
		} while (cond1 <= 0 || cond1 > 3); // unos

		switch (cond1) {

		case 1://delete id
			k = brojPlayera();
			obirisiPlayera(k);
			k--;
			if (ispisiLeaderboard(k) == -1) {
				return 1;
			}
			break;
		case 2://find id 
			k = brojPlayera();
			if (ispisiLeaderboard(k) == -1) {
				return 1;
			}
			int PlyID = siguranUnosINTa("\n\tUnesi ID trazenog Igraca: ", 0, 0);
			PLAYER_IG p = trazenjeID(k, PlyID);
			if (p.rank == -1) {
				printf("\n\tNema igraca, prvo kreirajte igrace odabirom opcije 2.\n\n");
				return 1;
			}
			break;
		case 3:// 3 opcija
			cond = 1;
			break;
		default:
			cond = 1;
		}
		break;
	case 4:
		cond = 0;
		break;

	default:
		cond = 0;
	}

	return cond;
}

