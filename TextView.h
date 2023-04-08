#include "Data.h"
#include <iostream>

class TextView {
public:
	// prints the current state of the board
	std::ostream& PrintBoard(std::ostream&);
	// shows the commands the player could make
	std::ostream& commands(std::ostream&);
	// shows the names of all the players
	std::ostream& DisplayNames(std::ostream&);
	// 
	std::ostream& ShowInfo(std::ostream&);
	//
	std::ostream& prog_messages(std::ostream&);
	// text-based menu screen with options
	std::ostream& menu(std::ostream&);
	// 
	std::ostream& MakeAction(std::ostream&);
};

