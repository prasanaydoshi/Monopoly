#ifndef DATA
#define DATA

#include <vector>
#include <map>
#include "Player.h"

class Data {

	Player *current;
	Player *bank;
	std::vector<Player*> players;
	//std::map<Property*, <int> board;
	std::vector<std::string> properties;
	std::vector<int> improvement;
	std::vector<Player*> dropout;
	public:
	Data(Player *current, Player *bank, std::vector<Player*> players, std::vector<Player*> dropout);
	Player *curPlayer();
};

#endif
