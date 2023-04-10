#include "board.h"

//BoardTile methods/constructors
BoardTiles::BoardTiles(std::string name, std::string block, int purchaseCost, bool purchasable)
    : name{name}, block{block}, purchaseCost{purchaseCost}, purchasable{purchasable}, owner{"Bank"} { }

BoardTiles::~BoardTiles() { }

std::string BoardTiles::getName() { return name;}

std::string BoardTiles::getOwner(){ return owner;}

void BoardTiles::setOwner(std::string ownerName) { owner = ownerName; }

int BoardTiles::getPurcahseCost() { return purchaseCost; }

std::string BoardTiles::getBlock() { return block; }

bool BoardTiles::isPurchasable() { return purchasable; }

//AcademicBuilding methods/constructors
AcademicBuilding::AcademicBuilding(std::string name, std::string block, int purchaseCost, bool purchasable, 
		int impCost, std::vector<int> tuitionCost) : 
	BoardTiles{name, block, purchaseCost, purchasable}, impCost{impCost}, tuitionCost{tuitionCost}, 
		mortgage{false}, impLevel{0} {}

AcademicBuilding::~AcademicBuilding() { }

int AcademicBuilding::getTuition() { return tuitionCost[impLevel]; }

void AcademicBuilding::improve() { ++impLevel; }

void AcademicBuilding::unimprove(){ --impLevel; }

void AcademicBuilding::changeMortage(){
    mortgage = !mortgage;
    return mortgage;
}
int AcademicBuilding::getImpCost() { return impCost; }

//Gym methods/constructors
Gym::Gym(std::string name, std::string block, int purchaseCost, bool purchasable) : 
	BoardTiles{name, block, purchaseCost, purchsable} { }

Gym::~Gym() { }

int Gym::getTuition() { return 10; }

//Residence methods/constructors
Residence::Residence(std::string name, std::string block, int purchaseCost, bool purchasable) : 
	BoardTiles{name, block, purchaseCost, purchasable} { }

Residence::~Residence() { }

int Residence::getTuition() { return 5; }

Notpurchasable::Notpurchasable(std::string name, std::string block, int purchaseCost, bool purchasable) : 
	BoardTiles{name, block, purchaseCost, purchasable} { }

Notpurchsable::~Notpurchasable() { }

int Notpurchasable::getTuition() { return 11; }
