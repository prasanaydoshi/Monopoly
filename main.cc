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

	std::string com;

	while(cin >> com){
		if(com == "roll"){
			commands->roll(1);
			//cout << "Rolled a " << i << "." << endl;
		}else if(com == "next"){
			commands->next();
		}else if(com == "trade"){
			commands->trade();
		}else if(com == "improve"){
			commands->improve();
		}else if(com == "mortgage"){
			commands->mortage();
		}else if(com == "unmortgage"){
			commands->unmortage();
		}else if(com == "bankrupt"){
			commands->assets();
		}else if(com == "assets"){
			commands->all();
		}else if(com == "save"){
			commands->saveGame();
		}else{
			std::cout << "Invalid Input" << std::endl;
		}
	}
	delete commands;
}
