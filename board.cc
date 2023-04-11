#include "board.h"

BoardTiles::BoardTiles(std::string name, std::string block, int purchaseCost, bool purchasable)
    : name{name}, block{block}, purchaseCost{purchaseCost}, purchasable{purchasable}, owner{"BANK"}, mortgage{mortgage}{
} 

BoardTiles::~BoardTiles(){}

std::string BoardTiles::getName(){
    return name;
}

std::string BoardTiles::getOwner(){
    return owner;
}

void BoardTiles::setOwner(std::string ownerName){
    owner = ownerName;
}

int BoardTiles::getPurcahseCost(){
    return purchaseCost;
}

std::string BoardTiles::getBlock(){
    return block;
}

bool BoardTiles::isPurchasable(){
    return purchasable;
}

bool BoardTiles::getMortgage(){
    return mortgage;
}

void BoardTiles::changeMortage(){
    if(mortgage == false){
        mortgage = true;
        return;
    }
    mortgage = false;
}

AcademicBuilding::AcademicBuilding(std::string name, std::string block, int purchaseCost, 
		bool purchasable, int impCost, std::vector<int> tuitionCost)
    :BoardTiles{name, block, purchaseCost, purchasable}, impCost{impCost}, 
    tuitionCost{tuitionCost}, mortgage{false}, impLevel{0}{

}

AcademicBuilding::~AcademicBuilding(){

}

int AcademicBuilding::getImpLevel(){
    return impLevel;
}

int AcademicBuilding::getTuition(int i){
    return tuitionCost[impLevel];
}

void AcademicBuilding::improve(){
    ++impLevel;
}

void AcademicBuilding::unimprove(){
    --impLevel;
}

int AcademicBuilding::getImpCost(){
    return impCost;
}

Gym::Gym(std::string name, std::string block, int purchaseCost, bool purchasable)
    :BoardTiles{name, block, purchaseCost, purchasable}{}

Gym::~Gym(){}

int Gym::getTuition(int i){
    if(i > 1){
        return 6;
    }else if(i > 0){
        return 4;
    }
}

Residence::Residence(std::string name, std::string block, int purchaseCost, bool purchasable)
    :BoardTiles{name, block, purchaseCost, purchasable}{}

Residence::~Residence(){}

int Residence::getTuition(int i){
    return i * 50;
}

Notpurchasable::Notpurchasable(std::string name, std::string block, int purchaseCost, bool purchasable)
    :BoardTiles{name, block, purchaseCost, purchasable}{}

Notpurchasable::~Notpurchasable(){}

int Notpurchasable::getTuition(int i){
    return -100;
}
