#ifndef _DATA_H
#define _DATA_H

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include "Player.h"
#include "board.h"

class Data {
	Player *current;
	int cur;
	Player *bank;
	std::vector<Player*> players;
	std::map<BoardTiles*, int> board;
	//std::vector<Player*> dropout;

	std::vector<BoardTiles*> Tiles;

public:
	//constructors
	Data();

	//destructors
	~Data();

	void printBlock();

	//Player in jail
	bool Data::playerInJail() const;

	void checkTile(int i) const;
	bool buy(int i);
	bool auction(int i);
	void getRent(int i) const;

	//set Players
	void setCurPlayer(int i);
	void setPlayers(std::string name, char piece);
	void getPlayerNames();

	//accessor
	Player *curPlayer();

	//nested accessors
	//std::string get_namePlayer(int i);
	//char get_piecePlayer(int i);
	int get_posPlayer(int i);

	//additional methods
	//int get_NetWorth();

	/*/
	
	//non-purchasable tile methods
	void TuitionPay();
	void OSAPcollect();
	void CoopFee();
	void OSAPcol();
	void TimsJail();
	void GoToJail();
	void SLC();
	void NH();*/
	
};

#endif
