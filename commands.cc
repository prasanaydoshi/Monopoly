#include "commands.h"

Commands::Commands():rolled{false}, player{0}, maxPlayer{0}{

}

Commands::~Commands(){
    delete data;
}

void Commands::initializePlayers(int a){
    std::string name = "";
    char piece = 'a';
    maxPlayer = 0;
    for(int i = 0; i < a; ++i){
        std::cin >> name;
        std::cin >> piece;
        data->setPlayers(name, piece);
    }
    data->setCurPlayer(0);
    data->getPlayerNames();
}

void Commands::roll(int i){
    if(rolled){
        std::cout << "already rolled" << std::endl;
        return;
    }
    std::cout << "enter die1" << std::endl;
    int die1 = 15;
    std::cin >> die1;
    std::cout << "enter die2" << std::endl;
    int die2 = 15;
    std::cin >> die2;
    std::cout << "Rolled a " << die1 << " & " << die2 << ". Total " << die1 + die2 << std::endl;
    if(data->playerInJail()){
        //check if they roll doubles or pay right
        if(die1 == die2){
            std::cout << "You are free." << std::endl;
            data->leaveTimsJail(true);
            data->checkTile(die1 + die2);
            std::cout << "Rolling again." << std::endl;
            roll(++i);
        }else{
            if(data->leaveTimsJail(false)){

            }
            std::cout << "In jail, try again next turn." << std::endl;
            data->leaveTimsJail(false);
        }
    }else{
        if(die1 == die2){
            if(i < 3){
                std::cout << "You rolled doubles!" << std::endl;
                data->checkTile(die1 + die2);
                std::cout << "Rolling again." << std::endl;
                roll(++i);
            }else{
                std::cout << "Rolled doubles three times. You are going to jail." << std::endl;
                data->goTimsJail();
                rolled = true;
            }
        }else{
            data->checkTile(die1 + die2);
            rolled = true;
        }
    }
}

void Commands::next(){
    if(rolled == false){
        rolled = true;
    }
    ++player;
    if(player >= maxPlayer){
        player = 0;
    }
    data->setCurPlayer(player);
    data->getCurPlayer();
}

void Commands::trade(std::string name, std::string give, std::string receive){
    
}

void Commands::improve(std::string property, bool buy){

}

void Commands::mortage(std::string property){

}

void Commands::unmortage(std::string property){

}

bool Commands::bankrupt(){
    return false;
}

void Commands::assets(){

}

void Commands::all(){

}