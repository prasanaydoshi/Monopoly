#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>

class BoardTiles{
private:
	std::string name;
	std::string block;
	int purchaseCost;
	bool purchasable;
	std::string owner;
	bool mortgage;

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
	bool getMortgage();
	void changeMortage();

	virtual int getTuition(int i) = 0;
};
 
class AcademicBuilding : public BoardTiles{
private:					//
	std::vector<int> tuitionCost;
	int impCost;
	bool mortgage;
	int impLevel;

public:
	//normal constructor
	AcademicBuilding(std::string name, std::string block, int purchaseCost = 0, bool purchasable = true, int impCost = 0, std::vector<int> tutitionCost = {0, 0, 0, 0, 0});
	//copy and move constructors

	//virtual AcademicBuilding(const AcademicBuilding &other) override;
	//virtual AcademicBuilding(AcademicBuilding &&other) override;
	//copy and move assignment operators
	//virtual AcademicBuilding&operator=(const AcademicBuilding &other) const;
	//virtual AcademicBuilding&operator=(AcademicBuilding &&other) const;

	//destructors
	~AcademicBuilding() override;

	int getImpLevel();

	int getTuition(int i) override;
	void improve();
	void unimprove();
	int getImpCost();
};

class Gym : public BoardTiles{
public:
	Gym(std::string name, std::string block, int purchaseCost = 0, bool purchasable = true);
	~Gym() override;
	int getTuition(int i) override;
};

class Residence : public BoardTiles{
public:
	Residence(std::string name, std::string block, int purchaseCost = 0, bool purchasable = true);
	~Residence() override;
	int getTuition(int i) override;
};

class Notpurchasable : public BoardTiles{
public:
	Notpurchasable(std::string name, std::string block, int purchaseCost = 0, bool purchasable = false);
	~Notpurchasable() override;
	int getTuition(int i) override;
};

#endif
