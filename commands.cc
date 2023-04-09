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

void Commands::roll(int i){
    int die1 = 2;
    int die2 = 2;
    std::cout << "Rolled a " << die1 << " & " << die2 << ". Total " << die1 + die2 << std::endl;
    if(data->playerInJail()){
        //check if they roll doubles or pay right
        std::cout << "In jail" << std::endl;
    }else{
        if(die1 == die2){
            if(i < 3){
                std::cout << "You rolled doubles, roll again." << std::endl;
                data->checkTile(die1 + die2);
                roll(++i);
            }else{
                std::cout << "Rolled doubles three times. You are going to jail." << std::endl;
            }
        }else{
            data->checkTile(die1 + die2);
        }
    }
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