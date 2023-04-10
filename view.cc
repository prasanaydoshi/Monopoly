#include "view.h"
/*
int getNoPlay() {
	return 6;
}

char charRep(int x) {
	if(x == 0) {
		return 'G'; } else if (x == 1) {return 'B';} else if (x == 2) {return 'D';} else if (x == 3) {return 'P';} 
	else if (x==4) {return 'S';} else {return '$';} 
}*/

void add_spaces(std::vector <std::string>& coord_spaces) {
	for (int it = 0; it < coord_spaces.size(); ++it) {
		if (coord_spaces[it].length() < 8) {
			for (int i = coord_spaces[it].length(); i < 8; i++) {
				coord_spaces[it].append(" ");
			}
		}
	}
}

void join(int start, int end, std::vector <std::string> coord_join) {
	std::string joint = "";
	if (start > end) {
		for (int i = start; i >= end; i--) {
			joint.append(coord_join[i]);
		}
	} else {	for (int i = start; i <= end; i++) {
		joint.append(coord_join[i]);
	}
	}
	std::cout << joint << "|" << std::endl;
}

void semi_main(std::vector<int> imp, std::vector<int> getPos, std::vector<char> get_char) {
	std::vector <std::string> properties = {"AL","ML","ECH","PAS","HH","RCH","DWE","CPH","LHI","BMH","OPT","EV1","EV2","EV3","PHYS","B1","B2","EIT","ESC","C2","MC","DC"};
	std::vector <std::string> tiles = {"COLLECT OSAP","AL","SLC","ML","TUTION","MKV","ECH","NEEDLES HALL","PAS","HH","DC TIMS LINE","RCH","PAC","DWE","CPH","UWP","LHI","SLC","BMH","OPT","GOOSE NESTING","EV1","NEEDLES HALL","EV2","EV3","V1","PHYS","B1","CIF","B2","GO TO TIMS","EIT","ESC","SLC","C2","REV","NEEDLES HALL","MC","COOP FEE","DC"};
	std::vector <std::string> coord(40, "|");
	std::vector <std::string> imp_coord(22, "|");
	//int noPlay = getNoPlay();
	//std::vector <int> imp {1,1,0,0,0,0,0,1,0,0,5,2,3,4,5,1,0,0,0,1,2,3};
	//std::vector <int> get_pos {0,0,0,0,0,0};
	//std::vector <char> get_char {'G','B','D','P','S','$'};

	for(int i = 0; i < getPos.size(); i++) {
		std::string tmp_char;
		//function called get_posPlayer(i)
		//int pos = get_pos[i];
		//which return position given a int
		tmp_char = get_char[i]; //should be get_piecePlayer(i);
		coord[getPos[i]].append(tmp_char);
	}
	for(int i = 0; i < properties.size(); i++) {
		if(imp[i] == 5) {
			imp_coord[i].append("^^^^C");
		} else if (imp[i] == 4) {
			imp_coord[i].append("^^^^");
		} else if(imp[i] == 3) {
			imp_coord[i].append("^^^");
		} else if (imp[i] == 2) {
			imp_coord[i].append("^^");
		} else if (imp[i] == 1) {
			imp_coord[i].append("^");
		} else {
		}
	}
	add_spaces(coord);
	add_spaces(imp_coord);
	std::cout << "_________________________________________________________________________________________" << std::endl;
	std::cout << "|Goose  "<< imp_coord[11] << "|NEEDLES" << imp_coord[12] << imp_coord[13] << "|V1     " << imp_coord[14] << imp_coord[15] << "|CIF    " << imp_coord[16] << "|GO TO  |" << std::endl;
	std::cout << "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |" << std::endl;
	std::cout << "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |" << std::endl;
	join(20,30, coord);
	std::cout << "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|" << std::endl;
	std::cout  <<imp_coord[10]<< "|" << "                                                                       " << imp_coord[17] << "|" << std::endl;
	std::cout << "|-------|                                                                       |-------|" << std::endl;
	std::cout << "|OPT    |                                                                       |EIT    |" << std::endl;
	std::cout << ""<< coord[19]<< "|" << "                                                                       " << coord[31] << "|" << std::endl;
	std::cout << "|_______|                                                                       |_______|" << std::endl;
	std::cout << "" << imp_coord[9]<< "|" << "                                                                       " << imp_coord[18] << "|" << std::endl;
	std::cout << "|-------|                                                                       |-------|" << std::endl;
	std::cout << "|BMH    |                                                                       |ESC    |" << std::endl;
	std::cout << coord[18]<< "|" << "                                                                       " << coord[32] << "|" << std::endl;
	std::cout << "|_______|                                                                       |_______|" << std::endl;
	std::cout << "|SLC    |                                                                       |SLC    |" << std::endl;
	std::cout <<  coord[17]<< "|" << "                                                                       " << coord[33] << "|" << std::endl;
	std::cout << "|       |                                                                       |       |" << std::endl;
	std::cout << "|       |                                                                       |       |" << std::endl;
	std::cout << "|_______|                                                                       |_______|" << std::endl;
	std::cout << imp_coord[8]<< "|" << "                                                                       " << imp_coord[19] << "|" << std::endl;
	std::cout << "|-------|                                                                       |-------|" << std::endl;
	std::cout << "|LHI    |                                                                       |C2     |" << std::endl;
	std::cout <<  coord[16]<< "|" << "             _____________________________________________             " << coord[34] << "|" << std::endl;
	std::cout << "|_______|            |                                             |            |_______|" << std::endl;
	std::cout << "|UWP    |            | #   #   ##  #####  ###   ###   ###  # #   # |            |REV    |" << std::endl;
	std::cout <<  coord[15]<< "|" << "            | #   #  #  #   #   #   #  #  # #   # # #   # |            " << coord[35] << "|" << std::endl;
	std::cout << "|       |            | # # #  ####   #   #   #  ###  #   # #  # #  |            |       |" << std::endl;
	std::cout << "|       |            | # # #  #  #   #   #   #  #    #   # #   #   |            |       |" << std::endl;
	std::cout << "|_______|            | #####  #  #   #    ###   #     ###  ### #   |            |_______|" << std::endl;
	std::cout << imp_coord[7]<< "|" << "            |_____________________________________________|            " << "|NEEDLES|" << std::endl;
	std::cout << "|-------|                                                                       |HALL   |" << std::endl;
	std::cout << "|CPH    |                                                                       |       |" << std::endl;
	std::cout << coord[14]<< "|" << "                                                                       " << coord[36] << "|" << std::endl;
	std::cout << "|_______|                                                                       |_______|" << std::endl;
	std::cout <<  imp_coord[6]<< "|" << "                                                                       " << imp_coord[20] << "|" << std::endl;
	std::cout << "|-------|                                                                       |-------|" << std::endl;
	std::cout << "|DWE    |                                                                       |MC     |" << std::endl;
	std::cout <<  coord[13]<< "|" << "                                                                       " << coord[37] << "|" << std::endl;
	std::cout << "|_______|                                                                       |_______|" << std::endl;
	std::cout << "|PAC    |                                                                       |COOP   |" << std::endl;
	std::cout << "|       |                                                                       |FEE    |" << std::endl;
	std::cout << "|       |                                                                       |       |" << std::endl;
	std::cout << coord[12]<< "|" << "                                                                       " << coord[38] << "|" << std::endl;
	std::cout << "|_______|                                                                       |_______|" << std::endl;
	std::cout << imp_coord[5]<< "|" << "                                                                       " << imp_coord[21] << "|" << std::endl;
	std::cout << "|-------|                                                                       |-------|" << std::endl;
	std::cout << "|RCH    |                                                                       |DC     |" << std::endl;
	std::cout << coord[11]<< "|" << "                                                                       " << coord[39] << "|" << std::endl;
	std::cout << "|_______|_______________________________________________________________________|_______|" << std::endl;
	std::cout << "|DC TIMS"<< imp_coord[4] << imp_coord[3] << "|NEEDLES" << imp_coord[2] << "|MKV    |TUTION " << imp_coord[1] <<"|SLC    " << imp_coord[0] << "|COLLECT|" << std::endl;
	std::cout << "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |" << std::endl;
	std::cout << "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |" << std::endl;
	join(10,0, coord);
	std::cout << "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|" << std::endl;
}
/*
std::ostream& commands(std::ostream& os) {
	os << "\nThe possible commands a Player can make include:\n";
	os << "	roll\n";
	os << "		roll : rolls two dice and moves player by their sum\n\n";
	os << "	next\n";
	os << "		next : when your turn is up, switches to next player in line\n\n";
	os << "	trade <name> <give> <receive>\n";
	os << "		trade : current player can request a trade from another player,";
	os << "must mention their name, what they are offering and what they want in return\n\n";
	os << "	improve <property> buy/sell\n";
	os << "		improve: current player can attempt to buy or sell an improvement"; 
	os << "for the mentioned property\n\n";
	os << "	mortgage <property>\n";
	os << "		mortgage : current player can attempt to mortgage the mentioned property\n\n";
	os << "	unmortgage <property>\n";
	os << "		unmortgage : current player can attempt to unmortgage the mentioned"; 
	os << "property\n\n";
	os << "	bankrupt\n";
	os << "		bankruptcy : player declares bankruptcy, only allowed when player owes more then"; 
	os << "their balance\n\n";
	os << "	assets\n";
	os << "		assets : displays assets of current player\n\n";
	os << "	all\n";
	os << "		all : displays assets of all players\n\n";
	os << "	save <filename>\n";
	os << "		save : saves the current state of game in a file with the mentioned"; 
	os << "filename\n\n";
	return os;
}*/

/*
void PrintBoard() {
	semi_main();
}
std::ostream& DisplayNames(std::ostream& os) {
	//for (int i = 0; i < get_noPlayers(); i++) {
	// os << get_namePlayer(i) << endl;
	//}
	return os;
}
std::ostream& ShowInfo(std::ostream& os) {
	//for (int i = 0; i < get_noPlayer(); i ++) {
	//os << "Player name: " << get_namePlayer(i) << " Player piece: " << get_piecePlayer(i) << " Position: " << get_posPlayer(i) << " Owned Properties: " << owned_assets(i) << " Balance: " << get_balPlayer(i)<< " No of tims cups: " << get_timscups(i) << " Is playe in jail?: " << get_inJail(i) << endl;
	//
	return os;
}
std::ostream& prog_messages(std::ostream& os) {
	return os;
}
std::ostream& menu(std::ostream& os) {
	return os;
}
std::ostream& MakeAction(std::ostream& os) {
	return os;
}

std::ostream& cur_assets(std::ostream& os) {
	//Game_data.cur_assets(os) << "\n";
	return os;
}

//shows assets of all players
std::ostream& all_assets(std::ostream& os) {
	/*int players = Game_data.get_noPlayers();
	  os << "Assets of Currenlty Active players:\n";
	  for (int i = 0; i <= players; ++i) {
	  os << "Playerno. " << i << " : ";
	  Game_data.owned_assets(i, os) << "/n";	
	  }
	return os;
}


int main() {
	PrintBoard();
}*/

