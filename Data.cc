#include "Data.h"


//constructor
Data::Data() : 
	current{nullptr}, bank{nullptr}, 
	board {
		std::make_unique<Notpurchasable>("COLLECT OSAP", "Collect OSAP", 0, false),
		std::make_unique<AcademicBuilding>("AL", "Arts1", 40, true, 50, 
			{2, 10, 30, 90, 160, 250}),
		std::make_unique<Notpurchasable>("SLC", "SLC", 0, false),
		std::make_unique<AcademicBuilding>("ML", "Arts1", 60, true, 50, 
			{4, 20, 60, 180, 320, 450}),
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
		players.emplace_back(std::make_unique<Player>(name, piece, timsCups, money, position));
	}
	std::string tile;
	std::string owner;
	int improvLevel;
	while (!is.eof()) {
		is >> tile >> owner >> improvLevel;
		board.emplace_back(std::make_unique<BoardTiles>(tile, owner, improvLevel));
	}
}

// 
void Data::printBlock(){
	//std::cout << board.size() << std::endl;
	for(int i = 0; i < 40; ++i){
		std::cout << board[i]->getName() << std::endl;
	}
}

void Data::checkTile(int i){
	current->movePosnBy(i);		//moves current players position by i
	if(current->getPosn() > 39){	//checks if cur player's posn exceeds 39
		collectOSAP();		//collects OSAP
		current->jumpToPosn(current->getPosn() - 39);	//player goes around board
	}
	std::cout << "Current Tile: " << board[current->getPosn()]->getName() << std::endl; //prints name of tile cur palyer is on
	if(board[current->getPosn()]->isPurchasable()){	//checks if tile cur player is on is purchasable
		if(board[current->getPosn()]->getOwner() == "Bank"){	//check if tile is owned by bank
			std::cout << "Do you want to buy " << board[current->getPosn()]->getName() << ". Yes/No" << std::endl;
			std::string response;
			std::cin >> response;
			if(response == "Yes"){
				if(buy()){
					std::cout << "Bought " << board[current->getPosn()]->getName() << "." << std::endl;
				}else{
					std::cout << "Going for auction." << std::endl;
					//auction();
				}
			}else{
				//auction function
			}

		}else{
			//must handle when tile is owned by another player
		}

	}else{
		std::cout << "not purchasable tile" << std::endl;
		//handle non_purchasable tiles
		if(board[current->getPosn()]->getName() == "GO TO TIMS"){
			std::cout << "going to jail" << std::endl;
			goToJail();
		}else if(board[current->getPosn()]->getName() == "GOOSE NESTING"){
			// handles what happens at gooseNesting tile
		}else if(board[current->getPosn()]->getName() == "TUITION"){
			//handles what happens at Tuition tile
		}else if(board[current->getPosn()]->getName() == "COOP FEE"){
			//handles what happens on COOP Fee tile
		}else if(board[current->getPosn()]->getName() == "SLC"){
			// handles what happens on SLC tile
		}else if(board[current->getPosn()]->getName() == "NEEDLES HALL"){
			// handles what happens on NEEDLES HALL tile
		}
	}
}

int Data::ownsProperty(std::string property){

	std::vector<int> tmpOwned = current->getProperties();
	for(int i = 0; i < tmpOwned.size(); ++i){
		if((board[tmpOwned[i]]->isPurchasable() != false) && (board[tmpOwned[i]]->getName() == property)){
			return tmpOwned[i];
		}
	}
	std::cout << "You don't own this property." << std::endl;
	return -1;
}

bool Data::leaveTimsJail(bool f){
	if(current->setJailRolls()){
		std::cout << "Must exit jail. Pay 50." << std:: endl;
		current->setInJail();
		if((current->getBalance()-50) < 0){
			std::cout << "Balance to low. Can't buy. Mortgage properties or declare bankruptcy." << std::endl;
			//mortage and bankruptcy
		}else{
			current->subMoney(50);
		}
		return false;
	}
	if(f){
		current->setInJail();
	}
	return true;
}

void Data::improve(std::string property){
	int index = ownsProperty(property);
	if (index >= 0){
		AcademicBuilding *tmp = dynamic_cast<AcademicBuilding*>(Tiles[index]);
		if((tmp->getImpLevel() < 5) && ((current->getBalance()-tmp->getImpCost()) > 0)){
			tmp->improve();
			current->subMoney(tmp->getImpCost());
			std::cout << tmp->getName() << " has " << tmp->getImpLevel() << " improvements." << std::endl;
		}else{
			std::cout << tmp->getName() << " currently at improve level " << tmp->getImpLevel() << ". Can't improve it, either maxed out or not enough funds." << std::endl;
		}
	}
}

void Data::unimprove(std::string property){
	int index = ownsProperty(property);
	if (index >= 0){
		AcademicBuilding *tmp = dynamic_cast<AcademicBuilding*>(board[index]);
		if(tmp->getImpLevel() != 0){
			tmp->unimprove();
			current->addMoney(tmp->getImpCost()/2);
			std::cout << tmp->getName() << " has " << tmp->getImpLevel() << " improvements." << std::endl;
		}else{
			std::cout << tmp->getName() << " currently at improve level " << tmp->getImpLevel() << ". Can't unimprove it anymore." << std::endl;
		}
	}
}


//nested accessors
std::string Data::getNamePlayer(int i) { return players[i]->getName(); }
void Data::getPlayerNames(){
	for(int i = 0; i < players.size(); ++i){
		std::cout << "Player Names: " << players[i]->getName() << ", Piece:" << players[i]->getPiece() << std::endl;
	}
}

char Data::getPiecePlayer(int i) { return players[i]->getPiece(); }
int Data::getPosPlayer(int i) { return players[i]->getPosn(); }
int Data::getNumPlayer() {
	int num = players.size();
	return num;
}
int Data::getBalPlayer(int i) { return players[i]->getBalance(); }

//other methods
int Data::getNetWorth() {
	int total_val = current->getBalance();		// current cash balance of player
	for (const auto& property : owned_properties) {		// going through list of owned properites
		int tileNo = property.second;			//sets tileno to be that being looked at
		total_val += board[tileNo].first->NetVal();	// adds netval of that property
	}
	return total_val;
}

std::ostream& Data::cur_assets(int i, std::ostream& out) {
	out << "Player Name: " << current->getName();
	out << "\nPlayer Balance: " << current->getBalance();
	out << "\nPlayer Properties:\n	";
	int owned = current->No_ownedProperties();
	int tileNo = 0;
	for (int propNo = 0; propNo <= owned; ++propNo) {
		tileNo = current->get_tileNo(propNo);
		out << current->getName() << "     with improvements: ";
		out << current->get_impLevel() << "\n";
	}
	return out;
}

std::ostream& Data::owned_assets(int i, std::ostream& out) {
	out << "Player Name: " << players[i]->getName();
	out << "\nPlayer Balance: " << players[i]->getBalance();
	out << "\nPlayer Properties:\n	";
	int owned = players[i]->No_ownedProperties();
	int tileNo = 0;
	for (int propNo = 0; propNo <= owned; ++propNo) {
		tileNo = players[i]->get_tileNo(propNo);
		out << board[tileNo]->getName() << "     with improvements: ";
		out << board[tileNo]->get_impLevel() << "\n";
	}
	return out;
}

void Data::save(std::ostream& os) const {
	os << players.size() << '\n';
	for (const auto& player : players) {
		os << player->getName() << player->getPiece() << ' ' << player->get_timscups();
	        os << ' ' << player->getBalance() << ' ' << player->getPosn() << '\n';
	}
	for (int i = 0; i <= 39; ++i) {
		os << get_TileName(i) << " " << get_TileOwner(i);
		os << " " << get_TileImpLevel(i) << "\n";
	}
	os.close();
}

bool Data::playerInJail() const{
	return current->isInJail();
}

bool Data::buy(){
	if((current->getBalance()-board[current->getPosn()]->getPurcahseCost()) < 0){
		std::cout << "Balance to low. Can't buy." << std::endl;
		return false;
	}
	board[current->getPosn()]->setOwner(current->getName());
	current->subMoney(board[current->getPosn()]->getPurcahseCost());
	current->addProperty(current->getPosn());
	return true;
}

void Data::setCurPlayer(int i){
	current = players[i];
	curPlayer = i;
}

void Data::setPlayers(std::string name, char piece){
	players.push_back(std::make_unique<Player>(name, piece));
}

//non-purchasable tile methods
void Data::TuitionPay(bool Pay300) {				// view will ask player if they want
								// to pay 300 or 10% of netval	
	if ( current->getPosn() == 24) {
		if (Pay300 == true) {
			current->change_balance(-300);
		} else {
			int net = getNetWorth();
			current->change_balance(net);
		}
	}
}

void Data::CoopFee() {
	if ( current->getPosn() == 18) {
		current->change_balance(-150);
	}
}

void Data::OSAPcol() {
	if ( current->getPosn() == 20) {
		current->change_balance(200);
	}
}

void Data::TimsJail() { 			
	//REQUIRES ROLL FUNCTION
	if ( current->getPosn() == 30) {
	}
}

void Data::GoToJail() {
	if ( current->getPosn() == 10) {
		current->JumpTo_posn(30);
	}
};

void Data::SLC() {
	if ( ( current->getPosn() == 13) || ( current->getPosn() == 13) ){
		std::random_device rd;
		std::mt19937 gen(rd());
		std::discrete_distribution<> d({1.0 / 8, 1.0 / 6, 1.0 / 6, 1.0 / 8,
			       	1.0 / 6, 1.0 / 6, 1.0 / 24, 1.0 /24});
		int num_pick = d(gen);			// REQUIRES RANDOM PICKING WITH %CHANCE
		switch(num_pick) {
			case 0:
				current->MovePosn_by(-3);		// back3
				break;
			case 1:
				current->MovePosn_by(-2);		// back2
				break;
			case 2:
				current->MovePosn_by(-1);		// back1
				break;
			case 3: 
				current->MovePosn_by(1);		// foreward1
				break;
			case 4: 
				current->MovePosn_by(2);		// foreward2
				break;
			case 5: 
				current->MovePosn_by(3);		// foreward3
				break;
			case 6: 
				current->JumpTo_posn(30);		// DC Tims Line
				break;
			case 7: 
				current->MovePosn_by(20);		// Collect OSAP
				break;
		}
	}
}

void Data::NH() {
	if (( current->getPosn() == 2) || ( current->getPosn() == 16) ){
		std::random_device rd;
		std::mt19937 gen(rd());
		std::discrete_distribution<> d({1.0 / 18, 1.0 / 9, 1.0 / 6, 1.0 / 3,
			       	1.0 / 6, 1.0 / 9, 1.0 / 18});
		int num_pick = d(gen);	
		switch(num_pick) {
			case 0:
				current->change_balance(-200);	 
				break;
			case 1:
				current->change_balance(-100);
				break;
			case 2:
				current->change_balance(-50);
				break;
			case 3:
				current->change_balance(25);	
				break;
			case 4: 
				current->change_balance(50);
				break;
			case 5: 
				current->change_balance(100);		
				break;
			case 6: 
				current->change_balance(200);
				break;
		}
	}
}

