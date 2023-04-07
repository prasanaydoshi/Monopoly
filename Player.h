#ifndef PLAYER
#define PLAYER

#include <vector>
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
	// accessors
	std::string get_name() const { return name; };
	char get_piece() const { return piece; };
	int get_posn() const { return posn; };
	int get_balance() const { return balance; };
	int get_timsCups() const { return timsCups; };

	// mutators
	void JumpTo_posn(int a) { posn = a; };
	void change_balance(int b) { balance += b; }
	
	void nextposn();
	std::string get_properties();
};

#endif
