#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <vector>
#include <string>
#include "Property.h"

class Player {
private:
	std::string name; 		//name of player
	char piece;        		// Piece representing player on board (G, B, D, P, S, $, L, T)
	int posn;			// current posn of player
	int balance;			// money owned by player
	int timsCups;			// no. of tims cups player owns
	std::vector<int> owned;
	bool inJail;
	int jailRolls;
	
public:
	// constructor
	Player(std::string name, char piece);      // player name, piece are entered during player construction
					// at start, posn = 0, balance = 1500, timsCups = 0;
	
	// accessors
	std::string getName() const;
	char getPiece() const;
	int getPosn() const;
	int getBalance() const;
	int getTimsCups() const;
	std::vector<int> getProperties() const;
	bool isInJail() const;
	int jailRollsCount() const;

//	int No_ownedProperties() const;
//	int get_TileNo(int i) const;

	// mutators
	void jumpToPosn(int a);
	void movePosnBy(int a);
	void subMoney(int a);
	void addMoney(int a);
	void addProperty(int a);
	void setInJail();
	bool setJailRolls();
	
	//methods
	void nextposn();                // moves player to next position this is a method 
					// and not a mutator, as after posn = 40, it resets to 0
					//
	//needs tile info, so moved higher, into data for now
//	int calc_NetWorth();		// Looks at balance and property values(including immprovements)
					// and calculates the net worth of the player
//	std::string get_properties();   // shows properties player owns
					// might later move this property to class owning player
					// as this is the only field causing need of Big5
};

#endif
