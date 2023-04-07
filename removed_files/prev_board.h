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
	//accessors
	std::string getBlock();
	int getPurchaseCost();
	int getTution(int level);
	int getImprovements();
	std::string getOwner();

	//mutators
	void improve();
	void unimprove();
	void changeMortage(bool current);
};

#endif

