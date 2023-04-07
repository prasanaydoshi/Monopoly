#include "board.h"

BoardTiles::BoardTiles(std::string name, std::string block, int purchaseCost, bool purchasable, std::string owner)
    : name{name}, block{block}, purchaseCost{purchaseCost}, purchasable{purchasable}, owner{owner}{
}

BoardTiles::~BoardTiles(){

}

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

AcademicBuilding::AcademicBuilding(std::string name, std::string block, int purchaseCost, bool purchasable, std::string owner, std::vector<int> tuitionCost, bool mortgage, int impLevel)
    :BoardTiles{name, block, purchaseCost, purchasable}, tuitionCost{tuitionCost}, mortgage{false}, impLevel{0}{

}

AcademicBuilding::~AcademicBuilding(){

}

int AcademicBuilding::getTuition(){

}

void AcademicBuilding::improve(){
    if(impLevel <= 5){
        ++impLevel;
    }
}

void AcademicBuilding::unimprove(){
    if(impLevel >= 0){
        --impLevel;
    }
}

void AcademicBuilding::changeMortage(){
    if(mortgage == false){
        mortgage = true;
    }
    mortgage = false;
}

int AcademicBuilding::getImprovements(){
    return impLevel;
}

int Gym::getTuition(){
    return 0;
}

int Residences::getTuition(){
    return 0;
}