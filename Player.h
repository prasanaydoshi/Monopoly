#ifndef PLAYER
#define PLAYER

#include <vector>
#include <string>
#include "Property.h"

class Player {
	std::string name;
	int posn;
	int balance;
	int timsCups;
	std::map<std::string, int> owned_properties;   // subject to change
//	std::vector<int> owned;
//	std::vector<Property*> owned;
	
public:
	// accessors
	int get_balance() const {return balance;};
	int get_posn() const {return posn;};
	std::string get_name() const {return name;};

	// mutators
	void JumpTo_posn(int a) { posn = a; };
	void change_balance(int b) { balance += b; }
	
	void nextposn();
	std::string get_properties();
};

#endif
