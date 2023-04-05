#ifndef PLAYER
#define PLAYER

#include <vector>
#include <string>
#include "Property.h"

class Player {
	int posn;
	int balance;
	std::vector<Property> owned;
//doesnt this require more fields??
	public:
	void changeposn();
	int get_balance();
	std::string get_properties();
};

#endif
