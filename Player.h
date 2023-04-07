#ifndef PLAYER
#define PLAYER

#include <map>
#include <string>
#include "Property.h"

class Player {
	std::string name;
	char piece;        // Piece representing player on board (G, B, D, P, S, $, L, T)
	int posn;
	int balance;
	int timsCups;
	std::map<std::string, int> owned_properties;   // subject to change
//	std::vector<int> owned;
//	std::vector<Property*> owned;
	
public:
	// constructor
	Player(std::string, char);      // player name, piece are entered during player construction
					// at start, posn = 0, balance = 1500, timsCups = 0;
	
	// accessors
	std::string get_name() const { return name; };
	char get_piece() const { return piece; };
	int get_posn() const { return posn; };
	int get_balance() const { return balance; };
	int get_timsCups() const { return timsCups; };

	// mutators
	void JumpTo_posn(int a) { posn = a; };
	void MovePosn_By(int a) { posn += a; };
	void change_balance(int b) { balance += b; }
	
	//methods
	void nextposn();                // moves player to next position this is a method 
					// and not a mutator, as after posn = 40, it resets to 0
	std::string get_properties();   // shows properties player owns
					// might later move this property to class owning player
					// as this is the only field causing need of Big5
};

#endif
