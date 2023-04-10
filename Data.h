#ifndef DATA
#define DATA

#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include "Player.h"
#include "board.h"

class Data {
	std::unique_ptr<Player> current;
	int curPlayer;
	bool rolled;
	std::unique_ptr<Player> bank;
	std::vector<std::unique_ptr<Player>> players;
	std::vector<std::unique_ptr<BoardTiles>> board;
	std::vector<std::unique_ptr<Player>> dropout;

public:
	//constructors
	Data();
	Data(std::istream& is); //loading constructor

	//destructor not needed due to smart pointers
	//	~Data();

	//accessor
	Player* curPlayer();

	//MISSING
	bool auction(int i);				// auctions a buliding 
	void getRent(int i) const;			// get rent of cur tile, removes from cur balance

	//why is this needed?
	void printBlock();				//? prints name of every tile in board
	void checkTile(int i) const;			//? checks if the tile after the curPlayer
							// is purchasable
	void getPlayerNames();				//? prints out all names of players
	
	//nested accessors
	bool playerInJail() const;
	int ownsProperty(std::string property);

	std::string getNamePlayer(int i);
	char getPiecePlayer(int i);
	int getPosPlayer(int i);
	int getNumPlayer(int i);
	int getBalPlayer(int i);

	std::string getTileName(int i);		// must be implemented
	std::string getTileOwner(int i);		//
	int getTileImpLevel(int i);		//

	//additional methods
	void checkTile(int i);
	void improve(std::string property);
	void unimprove(std::string property);

	int getNetWorth();
	std::string ownedAssets(int i);
	void save(std::ostream& os) const;
	bool playerInJail() const;		// returns whether player is in jail or not rn
	bool buy();				// purchases a building
	void setCurPlayer(int i);			// changes current player
	void setPlayers(std::string name, char piece);	// pushes back a new player 


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
