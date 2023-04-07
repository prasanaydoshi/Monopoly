#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

class Controller {
public:

	//buy and sell improvements
	void imp_buy(Player*, Property);
	void imp_sell(Player*, Property);

	// changes to next player in line
	void next_turn();

	// related to rolling dice
	int roll_func();
	int roll();
	int test_roll();

	// trade related
	void trade(Player*, std::string);
	void trade_offer(Player*);

	// mortgage related
	void mortgage();
	void unmortgage();

	// showing stuff owned by players
	std::ostream& owned_properties();
	std::ostream& all();
	
	// declaring bankruptcy
	void decl_bankrupt();

	// loading a file containing the state of a game of watopoly
	void load_game();

	// saving current state of game to a file
	void save();
};

#endif
