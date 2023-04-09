#ifndef _DATA_H
#define _DATA_H

#include <iostream>
#include <vector>
#include <map>
#include <random>
//#include "Player.h"
#include "board.h"

class Data {
	//Player *current;
	//Player *bank;
	//std::vector<Player*> players;
	//std::map<BoardTiles*, int> board;
	//std::vector<Player*> dropout;

	std::vector<BoardTiles*> Tiles;

public:
	//constructors
	Data();

	//destructors
	~Data();

	void printBlock();

	//accessor
	Player *curPlayer();

	//nested accessors
	std::string get_namePlayer(int i);
	char get_piecePlayer(int i);
	int get_posPlayer(int i);

	//additional methods
	int get_NetWorth();
	
	/*
	//non-purchasable tile methods
	void TuitionPay();
	void OSAPcollect();
	void CoopFee();
	void OSAPcol();
	void TimsJail();
	void GoToJail();
	void SLC();
	void NH();
	*/
};

#endif
