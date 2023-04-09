#ifndef DATA
#define DATA

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <random>
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

	//destructor
	~Data();

	//accessor
	Player *curPlayer();

	//MISSING
	bool Data::playerInJail() const;		// returns whether player is in jail or not rn
	bool buy(int i);				// purchases a building
	bool auction(int i);				// auctions a buliding 
	void getRent(int i) const;			// get rent of cur tile, removes from cur balance
	void setCurPlayer(int i);			// changes current player
	void setPlayers(std::string name, char piece);	// pushes back a new player 

	//why is this needed?
	void printBlock();				//? prints name of every tile in board
	void checkTile(int i) const;			//? checks if the tile after the curPlayer
							// is purchasable
	void getPlayerNames();				//? prints out all names of players
	
	//nested accessors
	std::string get_namePlayer(int i);
	char get_piecePlayer(int i);
	int get_posPlayer(int i);
	int get_numPlayer(int i);
	int get_BalPlayer(int i);

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
