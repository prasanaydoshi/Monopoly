#ifndef _board_h_
#define _board_h_
#include <iostream>
#include <string>

class BoardTiles{
	std::string name;
 public:
	std::string getName();
};

class CollectOsap : public BoardTiles{
public:
	void giveMoney();
};

class Purchasable : public BoardTiles{
	std::string block;
	int purchaseCost;
	int improveCost;
	std::string owner;
	int implevel;
	int tuition;
	bool mortgage;
public:
	std::string getBlock();
	int getPurchaseCost();
	int getTution(int level);
	void improve();
	void unimprove();
	void changeMortage(bool current);
	std::string getOwner();
	int getImprovements();
};

#endif

