#include "Data.h"


//constructor
Data::Data() : 
	current{nullptr}, bank{nullptr}, 
	Tiles {
		std::make_unique<Notpurchasable>("COLLECT OSAP", "Collect OSAP", 0, false),
		std::make_unique<AcademicBuilding>("AL", "Arts1", 40, true, 50, 
			{2, 10, 30, 90, 160, 250}),
		std::make_unique<Notpurchasable>("SLC", "SLC", 0, false);
		std::make_unique<AcademicBuilding>("ML", "Arts1", 60, true, 50, 
			{4, 20, 60, 180, 320, 450});
		std::make_unique<Notpurchasable>("TUITION", "Tuition", 0, false);
		std::make_unique<Residence>("MKV", "Residences", 200, true),
		std::make_unique<AcademicBuilding>("ECH", "Arts2", 100, true, 50, 
			{6, 30, 90, 270, 400, 550}),
		std::make_unique<Notpurchasable>("NEEDLES HALL", "Needles Hall", 0, false),
		std::make_unique<AcademicBuilding>("PAS", "Arts2", 100, true, 50, 
			{6, 30, 90, 270, 400, 550}),
		std::make_unique<AcademicBuilding>("HH", "Arts2", 120, true, 50, 
			{8, 40, 100, 300, 450, 600}),
		std::make_unique<Notpurchasable>("DC Tims Line", "DC Tims Line", 0, false),
		std::make_unique<AcademicBuilding>("RCH", "Eng", 140, true, 100, 
			{10, 50, 150, 450, 625, 750}),
		std::make_unique<Gym>("PAC", "Gyms", 150, true),
		std::make_unique<AcademicBuilding>("DWE", "Eng", 140, true, 100, 
			{10, 50, 150, 450, 625, 750}),
		std::make_unique<AcademicBuilding>("CPH", "Eng", 160, true, 100, 
			{12, 60, 180, 500, 700, 900}),
		std::make_unique<Residence>("UWP", "Residences", 200, true),
		std::make_unique<AcademicBuilding>("LHI", "Health", 180, true, 100, 
			{14, 70, 200, 550, 750, 950}),
		std::make_unique<Notpurchasable>("SLC", "SLC", 0, false),
		std::make_unique<AcademicBuildin>("BMH", "Health", 180, true, 100, 
			{14, 70, 200, 550, 750, 950}),
		std::make_unique<AcademicBuilding>("OPT", "Health", 200, true, 100, 
			{16, 80, 220, 600, 800, 1000}),
		std::make_unique<Notpurchasable>("Goose Nesting", "Goose Nesting", 0, false),
		std::make_unique<AcademicBuilding>("EV1", "Env", 220, true, 150, 
			{18, 90, 250, 700, 875, 1050}),
		std::make_unique<Notpurchasable>("NEEDLES HALL", "Needles Hall", 0, false),
		std::make_unique<AcademicBuilding>("EV2", "Env", 220, true, 150, 
			{18, 90, 250, 700, 875, 1050}),
		std::make_unique<AcademicBuilding>("EV3", "Env", 240, true, 150, 
			{20, 100, 300, 750, 925, 1100}),
		std::make_unique<Residence>("V1", "Residences", 200, true),
		std::make_unique<AcademicBuilding>("PHYS", "Sci1", 260, true, 150, 
			{22, 110, 330, 800, 975, 1150}),
		std::make_unique<AcademicBuilding>("B1", "Sci1", 260, true, 150, 
			{22, 110, 330, 800, 975, 1150}),
		std::make_unique<Gym>("CIF", "Gyms", 150, true),
		std::make_unique<AcademicBuilding>("B2", "Sci1", 280, true, 150, 
			{24, 120, 360, 850, 1025, 1200}),
		std::make_unique<Residence>("GO TO TIMES", "Go To Tims", 0, false),
		std::make_unique<AcademicBuilding>("EIT", "Sci2", 300, true, 200, 
			{26, 130, 390, 900, 1100, 1275}),
		std::make_unique<AcademicBuilding>("ESC", "Sci2", 300, true, 200, 
			{26, 130, 390, 900, 1100, 1275}),
		std::make_unique<Notpurchasable>("SLC", "SLC", 0, false),
		std::make_unique<AcademicBuilding>("C2", "Sci2", 320, true, 200, 
			{28, 150, 450, 1000, 1200, 1400}),
		std::make_unique<Residence>("REV", "Residences", 200, true),
		std::make_unique<Notpurchasable>("NEEDLES HALL", "Needles Hall", 0, false),
		std::make_unique<AcademicBuilding>("MC", "Math", 350, true, 200, 
			{35, 175, 500, 1100, 1300, 1500}),
		std::make_unique<Notpurchasable>("COOP FEE", "Coop Fee", 0, false),
		std::make_unique<AcademicBuilding>("DC", "Math", 400, true, 200, 
			{50, 200, 600, 1400, 1700, 2000})

	} { };		//default

Data::Data(std::istream& is) {					// for loading savefile
	int numPlayers;
	is >> numPlayers;
	for (int i = 0; i < numPlayers; ++i) {
		std::string name;
		char piece;
		int timsCups;
		int money;
		int position;
		is >> name >> piece >> timsCups >> money >> position;
		players.emplace_back(std::make_unique<Player>(name, piece, timsCups, money, poisition));
	}
	std::string tile;
	std::string owner
	int improvLevel;
	while (!is.eof()) {
		iss >> tile >> owner >> improvLevel;
		board.emplace_back(std::make_unique<BoardTiles>(tile, owner, improvLevel));
	}
}

// 

//nested accessors
std::string Data::get_namePlayer(int i) { return *(players[i]).get_name(); }
char Data::get_piecePlayer(int i) { return *(players[i]).get_piece(); }
int Data::get_posPlayer(int i) { return *(players[i]).get_posn(); }
int Data::get_numPlayer() {
	int num = players.size();
	return num;
}
int Data::get_
int Data::get_BalPlayer(int i) { return *(players[i]).get_balance(); }

//other methods
int Data::get_NetWorth() {
	int total_val = (*current).get_balance();		// current cash balance of player
	for (const auto& property : owned_properties) {		// going through list of owned properites
		int tileNo = property.second;			//sets tileno to be that being looked at
		total_val += (board[tileNo].first).NetVal();	// adds netval of that property
	}
	return total_val;
}

std::ostream& Data::cur_assets(int i, std::ostream& out) {
	out << "Player Name: " << *current.get_name();
	out << "\nPlayer Balance: " << *current.get_balance();
	out << "\nPlayer Properties:\n	";
	int owned = *current.No_ownedProperties();
	int tileNo = 0;
	for (int propNo = 0; propNo <= owned; ++propNo) {
		tileNo = *current.get_tileNo(propNo);
		out << *current.get_name() << "     with improvements: ";
		out << *current.get_impLevel() << "\n";
	}
	return out;
}

std::ostream& Data::owned_assets(int i, std::ostream& out) {
	out << "Player Name: " << *(players[i]).get_name();
	out << "\nPlayer Balance: " << *(players[i]).get_balance();
	out << "\nPlayer Properties:\n	";
	int owned = *(players[i]).No_ownedProperties();
	int tileNo = 0;
	for (int propNo = 0; propNo <= owned; ++propNo) {
		tileNo = *(players[i]).get_tileNo(propNo);
		out << *(board[tileNo]).get_name() << "     with improvements: ";
		out << *(board[tileNo]).get_impLevel() << "\n";
	}
	return out;
}

void Data::save(std::ostream& os) const {
	os << players.size() << '\n';
	for (const auto& player : players) {
		os << player->get_name() << player->get_piece() << ' ' << player->get_timscups();
	        os << ' ' << player->get_balance() << ' ' << player->get_posn() << '\n';
	}
	for (int i = 0; i <= 39; ++i) {
		os << get_TileName(i) << " " << get_TileOwner(i);
		os << " " << get_TileImpLevel(i) << "\n";
	}
	os.close();
}


//non-purchasable tile methods
void Data::TuitionPay(bool Pay300) {				// view will ask player if they want
								// to pay 300 or 10% of netval	
	if ( (*current).get_posn() == 24) {
		if (Pay300 == true) {
			(*current).change_balance(-300);
		} else {
			int net = get_NetWorth();
			(*current).change_balance(net);
		}
	}
}

void Data::CoopFee() {
	if ( (*current).get_posn() == 18) {
		(*current).change_balance(-150);
	}
}

void Data::OSAPcol() {
	if ( (*current).get_posn() == 20) {
		(*current).change_balance(200);
	}
}

void Data::TimsJail() { 			
	//REQUIRES ROLL FUNCTION
	if ( (*current).get_posn() == 30) {
	}
}

void Data::GoToJail() {
	if ( (*current).get_posn() == 10) {
		(*current).JumpTo_posn(30);
	}
};

void Data::SLC() {
	if ( ( (*current).get_posn() == 13) || ( (*current).get_posn() == 13) ){
		std::random_device rd;
		std::mt19937 gen(rd());
		std::discrete_distribution<> d({1.0 / 8, 1.0 / 6, 1.0 / 6, 1.0 / 8,
			       	1.0 / 6, 1.0 / 6, 1.0 / 24, 1.0 /24});
		int num_pick = d(gen);			// REQUIRES RANDOM PICKING WITH %CHANCE
		switch(num_pick) {
			case 0:
				(*current).MovePosn_by(-3);		// back3
				break;
			case 1:
				(*current).MovePosn_by(-2);		// back2
				break;
			case 2:
				(*current).MovePosn_by(-1);		// back1
				break;
			case 3: 
				(*current).MovePosn_by(1);		// foreward1
				break;
			case 4: 
				(*current).MovePosn_by(2);		// foreward2
				break;
			case 5: 
				(*current).MovePosn_by(3);		// foreward3
				break;
			case 6: 
				(*current).JumpTo_posn(30);		// DC Tims Line
				break;
			case 7: 
				(*current).MovePosn_by(20);		// Collect OSAP
				break;
		}
	}
}

void Data::NH() {
	if (( (*current).get_posn() == 2) || ( (*current).get_posn() == 16) ){
		std::random_device rd;
		std::mt19937 gen(rd());
		std::discrete_distribution<> d({1.0 / 18, 1.0 / 9, 1.0 / 6, 1.0 / 3,
			       	1.0 / 6, 1.0 / 9, 1.0 / 18});
		int num_pick = d(gen);	
		switch(num_pick) {
			case 0:
				(*current).change_balance(-200);	 
				break;
			case 1:
				(*current).change_balance(-100);
				break;
			case 2:
				(*current).change_balance(-50);
				break;
			case 3:
				(*current).change_balance(25);	
				break;
			case 4: 
				(*current).change_balance(50);
				break;
			case 5: 
				(*current).change_balance(100);		
				break;
			case 6: 
				(*current).change_balance(200);
				break;
		}
	}
}

