#include "TextView.h"

ostream& TextView::PrintBoard() {

};

// function to display commands to player:
ostream& TextView::commands(ostream& os) {
	os << "\nThe possible commands a Player can make include:\n";
	os << "	roll\n";
	os << "		roll : rolls two dice and moves player by their sum\n\n";
	os << "	next\n";
	os << "		next : when your turn is up, switches to next player in line\n\n";
	os << "	trade <name> <give> <receive>\n";
	os << "		trade : current player can request a trade from another player,";
	os << "must mention their name, what they are offering and what they want in return\n\n";
	os << "	improve <property> buy/sell\n";
	os << "		improve: current player can attempt to buy or sell an improvement 
	os << "for the mentioned property\n\n";
	os << "	mortgage <property>\n";
	os << "		mortgage : current player can attempt to mortgage the mentioned property\n\n";
	os << "	unmortgage <property>\n";
	os << "		unmortgage : current player can attempt to unmortgage the mentioned 
	os << "property\n\n";
	os << "	bankrupt\n";
	os << "		bankruptcy : player declares bankruptcy, only allowed when player owes more then 
	os << "their balance\n\n";
	os << "	assets\n";
	os << "		assets : displays assets of current player\n\n";
	os << "	all\n";
	os << "		all : displays assets of all players\n\n";
	os << "	save <filename>\n";
	os << "		save : saves the current state of game in a file with the mentioned 
	os << "filename\n\n";
	return os;
};

// function to display current playernames
ostream& TextView::DisplayNames(ostream& os) {
	int players = Game_data.get_noPlayers();
	os << "Currently still in-game:\n";
	for (int i = 0; i <= players; ++i) {
		os << "Playerno. " << i << " : " << Game_data.get_namePlayer(i);
	}
	return os;
};

ostream& TextView::ShowInfo() {
	
};

ostream& TextView::prog_messages() {
};

ostream& TextView::menu() {
};

ostream& TextView::MakeAction() {
};

// shows assets of current player
std::ostream& cur_assets(std::ostream& os) {
	Game_data.cur_assets(os) << "\n";
	return os;
};

//shows assets of all players
std::ostream& all_assets(std::ostream& os) {
	int players = Game_data.get_noPlayers();
	os << "Assets of Currenlty Active players:\n";
	for (int i = 0; i <= players; ++i) {
		os << "Playerno. " << i << " : ";
		Game_data.owned_assets(i, os) << "/n";	
	}
	return os;
};
