#ifndef DATA
#define DATA

#include <vector>
#include <map>
#include <random>
#include "Player.h"
#include  "board.h"

class Data {

	Player *current;
	Player *bank;
	std::vector<Player*> players;
	std::vector<BoardTiles*> Tiles;
	std::map<BoardTiles*, int> board;
	std::vector<Player*> dropout;

	std::vector<AcademicBuilding*> Arts1;
	std::vector<AcademicBuilding*> Arts2;
	std::vector<AcademicBuilding*> Eng;
	std::vector<AcademicBuilding*> Health;
	std::vector<AcademicBuilding*> Env;
	std::vector<AcademicBuilding*> Sci1;
	std::vector<AcademicBuilding*> Sci2;
	std::vector<AcademicBuilding*> Math;
	std::vector<Gym*> Gyms;
	std::vector<Residences*> Residences;

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
