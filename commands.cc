#include "commands.h"

Commands::Commands():rolled{false}, player{0}, maxPlayer{0}{

}

Commands::~Commands(){
    delete data;
}

void Commands::initializeGame(std::string fileName){
    std::ifstream file(fileName);
	if(!file) {
		std::cerr << "Failed to open file: " << fileName << '\n';
		return;
	}
    data->loadOldGame(file);
    data->setCurPlayer(player);
    data->getPlayerNames();
}

void Commands::save(){
    std::string fileName;
    std::cout << "Enter the filename: " << std::endl;
    std::cin >> fileName;
    std::ofstream file(fileName);
    data->save(file);					//
    file.close();
    /*if(!file){
        std::cerr << "Failed to save to file"
    }*/
    //data->saveGame(file);
}

void Commands::initializePlayers(int a){
    std::string name = "";
    char piece = 'a';
    maxPlayer = a;
    for(int i = 0; i < a; ++i){
        std::cin >> name;
        std::cin >> piece;
        data->setPlayers(name, piece);
    }
    data->setCurPlayer(player);
    data->getPlayerNames();
    std::cout << "Switched Players." << std::endl;
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
                std::cout << "In jail, try again next turn." << std::endl;
            }
            rolled = true;
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
    if(rolled == true){
        rolled = false;
    }
    ++player;
    if(player == maxPlayer){
        player = 0;
    }
    data->setCurPlayer(player);
}

void Commands::trade(){
    /*if ( (valid_property(bString[2], properties) && valid_property(bString[3], properties)) || (isDigit(bString[2]) && valid_property[3]) || (isDigit(bString[3]) && isDigit(bString[2]))) {
		for (int i = 0; i < player.size(); i++) {
			if(get_name(i) == bString[1]) {
				trade(bString[1], bString[2], bString[3]);
				break;
		    }
		}
    }*/

}

void Commands::improve(){
    std::string property;
    std::cin >> property;
    std::string buy;
    std::cin >> buy;
    if(buy == "buy"){
        data->improve(property);
    }else if(buy == "sell"){
        data->unimprove(property);
    }
}

void Commands::mortage(){
    std::string property;
    std::cin >> property;
    data->mortgage(property);
}

void Commands::unmortage(){
    std::string property;
    std::cin >> property;
    data->unmortage(property);
}

bool Commands::bankrupt(){
    return false;
}

void Commands::assets(){

}

void Commands::all(){

}
