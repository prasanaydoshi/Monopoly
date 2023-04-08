#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>

class BoardTiles{

	std::string name;
	int purchaseCost;
	std::string block;
	bool purchasable;
	std::string owner;

public:

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
	int getPurcahseCost();
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
	//normal constructor
	AcademicBuilding(std::string name, std::string block, int purchaseCost = 0, bool purchasable = true, int impLevel = 0, std::vector<int> tutitionCost = {0, 0, 0, 0, 0});
	//copy and move constructors

	//virtual AcademicBuilding(const AcademicBuilding &other) override;
	//virtual AcademicBuilding(AcademicBuilding &&other) override;
	//copy and move assignment operators
	//virtual AcademicBuilding&operator=(const AcademicBuilding &other) const;
	//virtual AcademicBuilding&operator=(AcademicBuilding &&other) const;

	//destructors
	virtual ~AcademicBuilding();

	int getTuition() override;
	void improve();
	void unimprove();
	void changeMortage();
	int getImprovements();
};

class Gym : public BoardTiles{
public:
	int getTuition() override;
};

class Residence : public BoardTiles{
public:
	int getTuition() override;
};

#endif
