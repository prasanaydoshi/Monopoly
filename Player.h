#ifndef PLAYER
#define PLAYER

#include <vector>
#include <string>
#include "Property.h"

class Player {
	int posn;
	int balance;
	std::vector<Property> owned;
	
	public:
	// accessors
	int get_balance() const {return balance;}
	int get_posn() const {return posn;}

	// mutators
	void nextposn() {
		if(posn < 40) {
			++posn;
		} else {
			posn = 0;
		};
	}
	void changeposn(int a) {
		posn = a;
	};
	int get_balance();
	std::string get_properties();
};

#endif
