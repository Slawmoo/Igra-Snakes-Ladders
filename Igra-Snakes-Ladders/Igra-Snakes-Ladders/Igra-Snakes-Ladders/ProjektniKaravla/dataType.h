#ifndef DATATYPE_H
#define DATATYPE_H

typedef struct player_ig {
	char nick[25];
	int boardPositionX;
	int boardPositionY;
	char tag;
}PLAYER_IG;

typedef struct player_lb{
	int rank;
	char nick[25];
	int winNum;
	int minMoves;
	//int bestTime; 
	
	//| Ranking | NickIgraca | BrojPobjeda | MinBrojPoteza | NajboljeVrijeme |
}PLAYER_LB;

#endif
