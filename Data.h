#ifndef DATA
#define DATA

#include <vector>
#include <map>
#include "Player.h"

class Data {

	Player *current;
	Player *bank;
	std::vector<Player*> players;
	std::vector<BoardTiles*> board;
	std::vector<Player*> dropout;

public:
	//constructors
	Data();

	//accessor
	Player *curPlayer();

	//nested accessors
	std::string get_namePlayer(int i);
	char get_piecePlayer(int i);
	int get_posPlayer(int i);

	//additional methods
	int get_NetWorth();
	std::sring owned_assets(int i);

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
