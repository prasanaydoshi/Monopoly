#include <iostream>
#include <string>
#include <vector>
#include "commands.h"

using namespace std;

int main(){
	Commands *commands = new Commands;
	cout << "How many players are playing!" << endl;
	int i = 0;
	cin >> i;
	cout << "Please name the players differently and pick from these pieces." << endl;
	commands->initializePlayers(i);
	std::string com;
	while(cin >> com){
		if(com == "roll"){
			commands->roll(1);

			//cout << "Rolled a " << i << "." << endl;
		}
	}
	delete commands;
}
