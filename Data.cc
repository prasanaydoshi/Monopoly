#include "Data.h"

//constructor
Data::Data() 
	:current{nullptr}, bank{nullptr},
	Tiles{
		new Notpurchasable{"COLLECT OSAP", "Collect OSAP", 0, false},
		new AcademicBuilding{"AL", "Arts1", 40, true, 50, {2, 10, 30, 90, 160, 250}},
		new Notpurchasable{"SLC", "SLC", 0, false},
		new AcademicBuilding{"ML", "Arts1", 60, true, 50, {4, 20, 60, 180, 320, 450}},
		new Notpurchasable{"TUITION", "Tuition", 0, false},
		new Residence{"MKV", "Residences", 200, true},
		new AcademicBuilding{"ECH", "Arts2", 100, true, 50, {6, 30, 90, 270, 400, 550}},
		new Notpurchasable{"NEEDLES HALL", "Needles Hall", 0, false},
		new AcademicBuilding{"PAS", "Arts2", 100, true, 50, {6, 30, 90, 270, 400, 550}},
		new AcademicBuilding{"HH", "Arts2", 120, true, 50, {8, 40, 100, 300, 450, 600}},
		new Notpurchasable{"DC TIMS LINE", "DC Tims Line", 0, false},
		new AcademicBuilding{"RCH", "Eng", 140, true, 100, {10, 50, 150, 450, 625, 750}},
		new Gym{"PAC", "Gyms", 150, true},
		new AcademicBuilding{"DWE", "Eng", 140, true, 100, {10, 50, 150, 450, 625, 750}},
		new AcademicBuilding{"CPH", "Eng", 160, true, 100, {12, 60, 180, 500, 700, 900}},
		new Residence{"UWP", "Residences", 200, true},
		new AcademicBuilding{"LHI", "Health", 180, true, 100, {14, 70, 200, 550, 750, 950}},
		new Notpurchasable{"SLC", "SLC", 0, false},
		new AcademicBuilding{"BMH", "Health", 180, true, 100, {14, 70, 200, 550, 750, 950}},
		new AcademicBuilding{"OPT", "Health", 200, true, 100, {16, 80, 220, 600, 800, 1000}},
		new Notpurchasable{"Goose Nesting", "Goose Nesting", 0, false},
		new AcademicBuilding{"EV1", "Env", 220, true, 150, {18, 90, 250, 700, 875, 1050}},
		new Notpurchasable{"NEEDLES HALL", "Needles Hall", 0, false},
		new AcademicBuilding{"EV2", "Env", 220, true, 150, {18, 90, 250, 700, 875, 1050}},
		new AcademicBuilding{"EV3", "Env", 240, true, 150, {20, 100, 300, 750, 925, 1100}},
		new Residence{"V1", "Residences", 200, true},
		new AcademicBuilding{"PHYS", "Sci1", 260, true, 150, {22, 110, 330, 800, 975, 1150}},
		new AcademicBuilding{"B1", "Sci1", 260, true, 150, {22, 110, 330, 800, 975, 1150}},
		new Gym{"CIF", "Gyms", 150, true},
		new AcademicBuilding{"B2", "Sci1", 280, true, 150, {24, 120, 360, 850, 1025, 1200}},
		new Residence{"GO TO TIMS", "Go To Tims", 0, false},
		new AcademicBuilding{"EIT", "Sci2", 300, true, 200, {26, 130, 390, 900, 1100, 1275}},
		new AcademicBuilding{"ESC", "Sci2", 300, true, 200, {26, 130, 390, 900, 1100, 1275}},
		new Notpurchasable{"SLC", "SLC", 0, false},	
		new AcademicBuilding{"C2", "Sci2", 320, true, 200, {28, 150, 450, 1000, 1200, 1400}},
		new Residence{"REV", "Residences", 200, true},
		new Notpurchasable{"NEEDLES HALL", "Needles Hall", 0, false},
		new AcademicBuilding{"MC", "Math", 350, true, 200, {35, 175, 500, 1100, 1300, 1500}},
		new Notpurchasable{"COOP FEE", "Coop Fee", 0, false},
		new AcademicBuilding{"DC", "Math", 400, true, 200, {50, 200, 600, 1400, 1700, 2000}}}{}

Data::~Data(){
	for (int i = 0; i < 40; ++i){
		delete Tiles[i];
	}
	for(int i = 0; i < players.size(); ++i){
		delete players[i];
	}
}

void Data::printBlock(){
	//std::cout << Tiles.size() << std::endl;
	for(int i = 0; i < 40; ++i){
		std::cout << Tiles[i]->getName() << std::endl;
	}
}

bool Data::playerInJail() const{
	return current->isInJail();
}

void Data::checkTile(int i){
	current->MovePosn_By(i);
	if(current->get_posn() > 39){
		OSAPcol();
		current->JumpTo_posn(current->get_posn() - 39);
	}
	std::cout << "Current Tile: " << Tiles[current->get_posn()]->getName() << std::endl;
	if(Tiles[current->get_posn()]->isPurchasable()){

		if(Tiles[current->get_posn()]->getOwner() == "Bank"){
			std::cout << "Do you want to buy " << Tiles[current->get_posn()]->getName() << ". Yes/No" << std::endl;
			std::string response;
			std::cin >> response;
			if(response == "Yes"){
				if(buy()){	
					std::cout << "Bought " << Tiles[current->get_posn()]->getName() << "." << std::endl;
				}else{
					std::cout << "Going for auction." << std::endl;
					//auction();
				}
			}else{
				//auction function
			}

		}else{

			//rent function

		} 

	}else{
		std::cout << "not purchasable tile" << std::endl;
		if(Tiles[current->get_posn()]->getName() == "GO TO TIMS"){
			std::cout << "going to jail" << std::endl;
			goTimsJail();
		}else if(Tiles[current->get_posn()]->getName() == "GOOSE NESTING"){

		}else if(Tiles[current->get_posn()]->getName() == "TUITION"){

		}else if(Tiles[current->get_posn()]->getName() == "COOP FEE"){

		}else if(Tiles[current->get_posn()]->getName() == "SLC"){

		}else if(Tiles[current->get_posn()]->getName() == "NEEDLES HALL"){

		}
	}
}

bool Data::buy(){
	if((current->get_balance()-Tiles[current->get_posn()]->getPurcahseCost()) < 0){
		std::cout << "Balance to low. Can't buy." << std::endl;
		return false;
	}
	Tiles[current->get_posn()]->setOwner(current->get_name());
	current->subMoney(Tiles[current->get_posn()]->getPurcahseCost());
	current->addProperty(current->get_posn());
	return true;
}

void Data::improve(std::string property){
	int index = ownsProperty(property);
	if (index >= 0){
		AcademicBuilding *tmp = dynamic_cast<AcademicBuilding*>(Tiles[index]);
		if((tmp->getImpLevel() < 5) && ((current->get_balance()-tmp->getImpCost()) > 0)){
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
		AcademicBuilding *tmp = dynamic_cast<AcademicBuilding*>(Tiles[index]);
		if(tmp->getImpLevel() != 0){
			tmp->unimprove();
			current->addMoney(tmp->getImpCost()/2);
			std::cout << tmp->getName() << " has " << tmp->getImpLevel() << " improvements." << std::endl;
		}else{
			std::cout << tmp->getName() << " currently at improve level " << tmp->getImpLevel() << ". Can't unimprove it anymore." << std::endl;
		}
	}
}

int Data::ownsProperty(std::string property){
	
	std::vector<int> tmpOwned = current->getProperties();
	for(int i = 0; i < tmpOwned.size(); ++i){
		if((Tiles[tmpOwned[i]]->isPurchasable() != false) && (Tiles[tmpOwned[i]]->getName() == property)){
			return tmpOwned[i];
		}
	}
	std::cout << "You don't own this property." << std::endl;
	return -1;
}

void Data::goTimsJail(){
	current->JumpTo_posn(10);
	current->setInJail();
}

bool Data::leaveTimsJail(bool f){
	if(current->setJailRolls()){
		std::cout << "Must exit jail. Pay 50." << std:: endl;
		current->setInJail();
		if((current->get_balance()-50) < 0){
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

void Data::OSAPcol() {
	(*current).addMoney(200);
}
/*
void Data::getRent(int i) const{

}

bool Data::auction(int i) const{
	std::vector<std::string> playersInAuction;
	std::vector<std::string> dropped;
	for(int i = 0; i < players.size(); ++i){
		playersInAuction.push_back(players[i]->get_name());
	}
	std::cout << Tiles[i]->getName() << "is up for auction. Highest bidder wins." << std::endl;
	std::cout << "Enter your amount when your player piece shows up. Amount must be higher than " << Tiles[i]->getPurcahseCost() << "." << std::endl;
	std::cout << "If you chose to withdraw. "
	return false;
}*/

void Data::setCurPlayer(int i){
	current = players[i];
	curPlayer = i;
	std::cout << players[i] << std::endl;
}

void Data::setPlayers(std::string name, char piece){
	players.push_back(new Player{name, piece});
}

void Data::getPlayerNames(){
	for(int i = 0; i < players.size(); ++i){
		std::cout << "Player Names: " << players[i]->get_name() << ", Piece:" << players[i]->get_piece() << std::endl;
	}
}

/*
//nested accessors
std::string Data::get_namePlayer(int i) { return *(players[i]).get_name(); }
char Data::get_piecePlayer(int i) { return *(players[i]).get_piece(); }
*/
int Data::get_posPlayer(int i) {
	return players[i]->get_posn();
}

/*
//other methods
int Data::get_NetWorth() {
	int total_val = (*current).get_balance();		// current cash balance of player
	for (const auto& property : owned_properties) {		// going through list of owned properites
		int tileNo = property.second;			//sets tileno to be that being looked at
		total_val += (board[tileNo].first).NetVal();	// adds netval of that property
	}
	return total_val;
}*/


/*
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
*/
