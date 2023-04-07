#ifndef DATA
#define DATA

#include <vector>
#include <map>
#include "Player.h"

class Data {

	Player *current;
	Player *bank;
	std::vector<Player*> players;
	std::map<Property*, <int> board;
	std::vector<Player*> dropout;

public:
	//constructors
	Data();

	//accessor
	Player *curPlayer();

	//non-purchasable tile methods
	void TuitionPay();
	void OSAPcollect();
	void CoopFee();
	void OSAPcol();
	void TimsJail();
	void GoToJail();
	void SLC();
	void NH();
};

#endif
