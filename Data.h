#ifndef DATA
#define DATA

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "Player.h"
#include "BoardTiles.h"

class Data {
	std::unique_ptr<Player> current;
	std::unique_ptr<Player> bank;
	std::vector<std::unique_ptr<Player>> players;
	std::vector<std::unique_ptr<BoardTiles>> board;
	std::vector<std::unique_ptr<Player>> dropout;

public:
	//constructors
	Data();
	Data(std::istream& is); //loading constructor

	//accessor
	Player *curPlayer();

	//nested accessors
	std::string get_namePlayer(int i);
	char get_piecePlayer(int i);
	int get_posPlayer(int i);

	std::string get_TileName(i);		// must be implemented
	std::string get_TileOwner(i);		//
	int get_TileImpLevel(i);		//

	//additional methods
	int get_NetWorth();
	std::string owned_assets(int i);
	void save(std::ostream& os) const;

	//non-purchasable tile methods
	void payTuition();
	void collectOSAP();
	void payCoopFee();
	void GoToJail();
	void TimsJail();
	void SLC();
	void NH();
};

#endif
