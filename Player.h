#ifndef PLAYER
#define PLAYER

#include <vector>
#include <string>
#include "Property.h"

class Player {
	std::string name;
	int posn;
	int balance;
	std::vector<Property> owned;
	std::vector<int> rent;
//doesnt this require more fields??
	public:
	void changeposn();
	int get_balance();
	std::string get_properties();
};

#endif
