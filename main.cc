#include <iostream>
#include <string>
#include <vector>
#include "commands.h"

using namespace std;

int main(int argc, char* argv[]){
	Commands *commands = new Commands;

	if(argc > 1){
		cout << "Loading Game!" << std::endl;
		if(std::string(argv[1]) == "-load"){
			commands->initializeGame(argv[2]);
		}
	}else{
		cout << "Welcome to the sad world of Watopoly!" << endl;
		cout << "How many players are playing!" << endl;
		int i = 0;
		cin >> i;
		cout << "Please name the players differently and pick from these pieces." << endl;
	
		commands->initializePlayers(i);
	}

	std::string input;

	while(cin >> input){
		if(input == "quit") {			//quits from game
			break;
		} else if(input == "roll"){		//rolls dice
			commands->roll(1);
			//cout << "Rolled a " << i << "." << endl;
		}else if(input == "next"){		//ends current players turn,swaps to next Player
			commands->next();
		}else if(input == "trade"){		//trading owned properties/cash
			commands->trade();
		}else if(input == "improve"){		//improve owned property
			commands->improve();
		}else if(input == "mortgage"){		//mortgage owned property
			commands->mortage();
		}else if(input == "unmortgage"){	//unmortgage owned property
			commands->unmortage();
		}else if(input == "bankrupt"){		//declare bankruptcy
			commands->assets();
		}else if(input == "assets"){		//show all assets
			commands->all();
		}else if(input == "save"){		//saves gamestate
			commands->save();
		}else{
			std::cout << "Invalid Input" << std::endl;
		}
	}
	delete commands;
}
