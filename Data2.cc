#include "Data.h"

//constructors
Data::Data() : current{nullptr}, bank{nullptr}, board{ } { } //put in tiles


void Data::printBlock() {
	for(int i = 0; i < 40; ++i) {
		std::cout << board[i]->getName() << std::endl;
	}
}

void Data::checkTile(int i){
	current->movePosnBy(i);		//moves current players position by i
	if(current->getPosn() > 39){	//checks if cur player's posn exceeds 39
		collectOSAP();		//collects OSAP
		current->jumpToPosn(current->getPosn() - 39);	//player goes around board
	}
	std::cout << "Current Tile: " << board[current->getPosn()]->getName() << std::endl; //prints name of tile cur palyer is on
	if(board[current->getPosn()]->isPurchasable()){	//checks if tile cur player is on is purchasable
		if(board[current->getPosn()]->getOwner() == "Bank"){	//check if tile is owned by bank
			std::cout << "Do you want to buy " << board[current->getPosn()]->getName() << ". Yes/No" << std::endl;
			std::string response;
			std::cin >> response;
			if(response == "Yes"){
				if(buy()){
					std::cout << "Bought " << board[current->getPosn()]->getName() << "." << std::endl;
				}else{
					std::cout << "Going for auction." << std::endl;
					//auction();
				}
			}else{
				//auction function
			}

		}else{
			//must handle when tile is owned by another player
		}

	}else{
		std::cout << "not purchasable tile" << std::endl;
		//handle non_purchasable tiles
		if(board[current->getPosn()]->getName() == "GO TO TIMS"){
			std::cout << "going to jail" << std::endl;
			goToJail();
		}else if(board[current->getPosn()]->getName() == "GOOSE NESTING"){
			// handles what happens at gooseNesting tile
		}else if(board[current->getPosn()]->getName() == "TUITION"){
			//handles what happens at Tuition tile
		}else if(board[current->getPosn()]->getName() == "COOP FEE"){
			//handles what happens on COOP Fee tile
		}else if(board[current->getPosn()]->getName() == "SLC"){
			// handles what happens on SLC tile
		}else if(board[current->getPosn()]->getName() == "NEEDLES HALL"){
			// handles what happens on NEEDLES HALL tile
		}
	}
}

void Data::getPlayerNames(){
	for(int i = 0; i < players.size(); ++i){
		std::cout << "Player Names: " << players[i]->getName() << ", Piece:";
		std::cout << players[i]->getPiece() << std::endl;
	}
}

