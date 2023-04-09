#include "Controller.h"
#include "Data.h"
#include "command.h"

//making improvements
void Controller::imp_buy(Player *cur, Property) {
};
void Controller::imp_sell(Player *cur, Property) {
};

//changing player/related
void Controller::next_turn() {
};
int Controller::roll_func() {
};
int Controller::roll() {
};
int Controller::test_roll() {
};

//trading
void Controller::trade(Player *cur, std::string target) {
};
void Controller::trade_offer(Player *cur) {
};

//mortgaging
void Controller::mortgage() {
};
void Controller::unmortgage() {
};

//showing assets
std::ostream& Controller::owned_properties() {
};
std::ostream& Controller::all() {
};

void Controller::decl_bankrupt() {

};

void Controller::load(const std::string& fileName, Data& data) {
	std::ifstream file(filename);
	if(!file) {
		std::cerr << "Failed to open file: " << fileName << '\n';
		return;
	}
	data = Data(file);
};

void Controller::save(const std::string& fileName, const Data& data) {
	std::ofstream file(fileName);
	if (!file) {
		std::cerr << "Failed to open file: " << fileName << '\n';
		return;
	}
	data.save(file);
};

