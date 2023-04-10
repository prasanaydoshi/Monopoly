#ifndef _BOARD_H_
#define _BOARD_H_
#include <iostream>
#include <string>
#include <vector>
#include "commands.h"

class BoardTiles{

	std::string name;
	std::string block;
	int purchaseCost;
	bool purchasable;
	std::string owner;

public:
	//default constructor
	BoardTiles();

	//normal constructor
	BoardTiles(std::string name, std::string block, int purchaseCost = 0, bool purchasable = true);
	//copy and move constructors
	//virtual BoardTiles(const BoardTiles &other);
	//virtual BoardTiles(BoardTiles &&other);
	//copy and move constructors
	//virtual BoardTiles&operator=(const BoardTiles &other);
	//virtual BoardTiles&operator=(BoardTiles &&other);

	//destructors
	virtual ~BoardTiles();

	//accessors and mutators for some of the fields
	std::string getName();
	std::string getOwner();
	void setOwner(std::string ownerName);
	int getPurchaseCost();
	std::string getBlock();
	bool isPurchasable();
	virtual int getTuition() = 0;
};

class AcademicBuilding : public BoardTiles{

	std::vector<int> tuitionCost;
	int impCost;
	bool mortgage;
	int impLevel;

public:
	//default constructor
	AcademicBuilding();
	//constructor
	AcademicBuilding(std::string name, std::string block, int purchaseCost = 0, bool purchasable = true,
		       	int impCost = 0, std::vector<int> tuitionCost = {0, 0, 0, 0, 0});
	//copy and move constructors
	//virtual AcademicBuilding(const AcademicBuilding &other) override;
	//vritual AcademicBuilding(AcademicBuilding &&other) override;
	//copy and move assignment operators
	//virtual AcademicBuilding&operator=(const AcademicBuilding &other) const;
	//virtual AcademicBuilding&operator=(AcademicBuilding &&other) const;

	//destructors
	virtual ~AcademicBuilding() override;

	int getImpLevel();

	int getTuition() override;
	void improve();
	void unimprove();
	void changeMortage();
	int getImpCost();
};

class Gym : public BoardTiles{
public:
	//constructor
	Gym(std::string name, std::string block, int purchaseCost = 0, bool purchasable = true);
	//destructor
	virtual ~Gym() {}
	//getTution function
	int getTuition() override;
};

class Residences : public BoardTiles{
public:
	//constructor
	Residence(std::string name, std::string block, int purchaseCost = 0, bool purchasable = true);
	//destructor
	virtual ~Residence() { }
	//getTution function
	int getTuition() override;
};

class Notpurchasable : public BoardTiles{
public:
	//constructor
	Notpurchasable(std::string name, std::string block);
	//destructor
	virtual ~Notpurchasable() {};
	//getTuition function
	int getTuition() override;
};

#endif

