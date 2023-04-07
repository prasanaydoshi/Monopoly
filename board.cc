#include "board.h"

BoardTiles::BoardTiles(std::string name, std::string owner, int purchaseCost, bool purchasable)
    : name{name}, owner{owner}, purchaseCost{purchaseCost}, block{block}, purchasable{purchasable}{
}

BoardTiles::~BoardTiles(){

}

std::string BoardTiles::getName(){
    return name;
}

