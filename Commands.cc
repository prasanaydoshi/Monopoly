#include "Commands.h"
#include "Data.h"

//making improvements
void Commands::imp_buy(Player *cur, Property) {
};
void Commands::imp_sell(Player *cur, Property) {
};

//changing player/related
void Commands::next_turn() {
};
int Commands::roll_func() {
};
int Commands::roll() {
};
int Commands::test_roll() {
};

//trading
void Commands::trade(Player *cur, std::string target) {
};
void Commands::trade_offer(Player *cur) {
};

//mortgaging
void Commands::mortgage() {
};
void Commands::unmortgage() {
};

//showing assets
std::ostream& Commands::owned_properties() {
};
std::ostream& Commands::all() {
};

void Commands::decl_bankrupt() {

};

void Commands::load(const std::string& fileName, Data& data) {
	std::ifstream file(filename);
	if(!file) {
		std::cerr << "Failed to open file: " << fileName << '\n';
		return;
	}
	data = Data(file);
};

void Commands::save(const std::string& fileName, const Data& data) {
	std::ofstream file(fileName);
	if (!file) {
		std::cerr << "Failed to open file: " << fileName << '\n';
		return;
	}
	data.save(file);
};

