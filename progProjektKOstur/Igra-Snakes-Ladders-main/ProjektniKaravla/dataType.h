#ifndef DATATYPE_H
#define DATATYPE_H

typedef struct player {
	int ID; // ++
	char nick[15]; // ++
	int boardPositionX; // ja postavljam 
	int boardPositionY; // ja postavljam 
	char tag[2]; // ++ 
	int rank; // ja racunam
	int winNum;// ja racunam

	//| RANK | ID | Nick Igraca | Broj Pobjeda | Oznaka Igraca |
}PLAYER_IG;

#endif
