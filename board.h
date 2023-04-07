#ifndef _board_h_
#define _board_h_
#include <iostream>
#include <string>
#include <vector>
#include "commands.h"

class BoardTiles{
	std::string name;
	int purchaseCost;
	std::string owner;
	std::string block;

public:
	//normal constructor
	BoardTiles(std::string name, std::string owner = "bank", int purchaseCost = 0);
	//copy and move constructors
	virtual BoardTiles(const BoardTiles &other);
	virtual BoardTiles(BoardTiles &&other);
	//copy and move constructors
	virtual BoardTiles&operator=(const BoardTiles &other);
	virtual BoardTiles&operator=(BoardTiles &&other);

	//destructors
	virtual ~BoardTiles();

	//accessors and mutators for some of the fields
	std::string getName();
	void setName(std::string propertyName);
	std::string getOwner();
	void setOwner(std::string ownerName);
	int getPurcahseCost();
	void setPurchaseCost(int cost);
	std::string getBlock();
	void setBlock(std::string blockName);

	virtual bool purchasable();
};

class AcademicBuilding : public BoardTiles{

	std::vector<int*> tuitionCost;
	bool mortgage;
	int impLevel;

public:
	//normal constructor
	AcademicBuilding(int purchaseCost, int improveCost, std::)
	

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
