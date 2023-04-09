#include "commands.h"

Commands::Commands(){

}

Commands::~Commands(){
    delete data;
}

void Commands::initializePlayers(int a){
    std::string name = "";
    char piece = 'a';
    for(int i = 0; i < a; ++i){
        std::cin >> name;
        std::cin >> piece;
        data->setPlayers(name, piece);
    }
    data->setCurPlayer(0);
    data->getPlayerNames();
}

int Commands::roll() const{
    int die1 = 2;
    int die2 = 3;
    if(data->playerInJail()){
        //check if they roll doubles or pay right
    }else{
        data->checkTile(die1 + die2);
    }
    return 2;
}

void Commands::next() const{

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