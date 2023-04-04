#ifndef DATA
#define DATA

#include <vector>
#include <map>
#include "Player.h"

class Data {

	Player *current;
	Player *bank;
	std::vector<Player*> players;
	std::map<Property*, int> board;
	std::vector<Player*> dropout;

};

#endif
