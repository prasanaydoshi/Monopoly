#ifndef _DATA_H
#define _DATA_H

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include "Player.h"
#include "board.h"
#include "view.h"

class Data {
	Player *current;
	int curPlayer;
	bool rolled;
	Player *bank;
	//Need to add to the 
	int numOfTimsCups;
	std::vector<Player*> players;
	std::map<BoardTiles*, int> board;
	//std::vector<Player*> dropout;

	std::vector<BoardTiles*> Tiles;

public:
	//constructors
	Data();

	//destructors
	~Data();

	//set and save board
	void loadOldGame(std::istream& is);
	void save(std::ostream& os);
	
	int getNoPlayers();					//
	int curPlayerNo();					//
	//void printBlock();
	void printBoard();

	void checkTile(int i);
	bool buy();
	/*bool auction(int i);
	void getRent(int i) const;*/
	void improve(std::string property);
	void unimprove(std::string property);
	void mortgage(std::string property);
	void unmortage(std::string property);
	int ownsProperty(std::string property);
	bool checksMonopoly(std::string property);
	int getPropertyIndex(std::string property);
	std::vector<int> propertiesOnMonopoly(std::string block);
	void assets();

	//Player in jail
	bool playerInJail() const;
	void goTimsJail();
	bool leaveTimsJail(bool f);
	void OSAPcol();
	void SLC();
	void NH();

	//set Players
	void setCurPlayer(int i);
	void setPlayers(std::string name, char piece);
	void getPlayerNames();

	//accessor
	//Player *curPlayer();

	//nested accessors
	std::string getName();
	//char get_piecePlayer(int i);
	int get_posPlayer(int i);

	//additional methods
	//int get_NetWorth();


/*	
	//non-purchasable tile methods
	void TuitionPay();
	void OSAPcollect();
	void CoopFee();
	
	void GoToJail();
*/	
};

#endif
