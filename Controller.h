#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

class Controller {
public:

	//buy and sell improvements
	void imp_buy();
	void imp_sell();

	// changes to next player in line
	void next_turn();

	// related to rolling dice
	void roll_func();
	void roll();
	void test_roll();

	// trade related
	void trade();
	void trade_offer();

	// mortgage related
	void mortgage();
	void unmortgage();

	// showing stuff owned by players
	void owned_properties();
	void all();
	
	// declaring bankruptcy
	void decl_bankrupt();

	// loading a file containing the state of a game of watopoly
	void load_game();

	// saving current state of game to a file
	void save();
};

#endif
