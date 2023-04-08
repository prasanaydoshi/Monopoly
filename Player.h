#ifndef PLAYER
#define PLAYER

#include <vector>
#include <string>
//#include "Property.h"

class Player {
	std::string name;
	int posn;
	int balance;
	std::vector<int> owned;
int timsCups;	
//doesnt this require more fields??
	public:
	void changeposn();
	int get_balance();
	std::string get_properties();
};

#endif
