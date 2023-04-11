#include "Data.h"

//constructor
Data::Data() 
	:current{nullptr}, bank{nullptr}, owedPlayer{},
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

int Data::getNoPlayers() { return static_cast<int>(players.size()); } 	//

std::string Data::getName() { return current->get_name(); }

Data::~Data(){
	for (int i = 0; i < 40; ++i){
		delete Tiles[i];
	}
	for(int i = 0; i < getNoPlayers(); ++i){
		delete players[i];
	}
}
/*
void Data::printBlock(){
	//std::cout << 40 << std::endl;
}*/

int Data::curPlayerNo() { 					// got an element for this, could remove
	std::string Name = current->get_name();
	for (int i = 0; i < getNoPlayers(); ++i) {
		if (players[i]->get_name() == Name) {
			return i;
		}
	}
	return 0;
}
	


void Data::printBoard(){
	std::vector<int> impLevel;
	for(int i = 0; i < 40; ++i){
		if(Tiles[i]->isPurchasable()){
			if(Tiles[i]->getBlock() != "Gyms" && Tiles[i]->getBlock() != "Residences"){
				AcademicBuilding *t = dynamic_cast<AcademicBuilding*>(Tiles[i]);
				impLevel.push_back(t->getImpLevel());
			}
		}
	}
	std::vector<int> pos;
	for(int i = 0; i < getNoPlayers(); ++i){
		pos.push_back(players[i]->get_posn());
	}
	std::vector<char> piece;
	for(int i = 0; i < getNoPlayers(); ++i){
		piece.push_back(players[i]->get_piece());
	}
	semi_main(impLevel, pos, piece);
}

void Data::loadOldGame(std::istream& is){
	int numPlayers;
	is >> numPlayers;
	for (int i = 0; i < numPlayers; ++i) {
		std::string name;
		char piece;
		int timsCups;
		int money;
		int position;
		is >> name >> piece >> timsCups >> money >> position;
		bool inJail = false;
		int jailTurns = 0;
		if(position == 10){
			is >> inJail;
			if(inJail == 1){
				is >> jailTurns;
			}
		}
		players.push_back(new Player{name, piece, position, money, timsCups, inJail, jailTurns});
	}
	/*for(int i = 0; i < getNoPlayers(); ++i){
		setCurPlayer(i);
		std::cout << current->get_name() << " " << current->get_piece() << " " << current->get_timsCups() << " " << current->get_balance() << " " << current->get_posn() << " ";
		if(current->get_posn() == 10){
			if(current->isInJail()){
				std::cout << current->isInJail() << " " << current->jailRollsCount();
			}else{
				std::cout << current->isInJail();	
			}
		}
		std::cout << std::endl;
	}*/
	for(int i = 0; i < Tiles.size(); ++i){
		std::string name;
		std::string owner;
		int improve;
		is >> name >> owner >> improve;
		if(Tiles[i]->getName() == name){
			Tiles[i]->setOwner(owner);
			if(improve < 0){
				Tiles[i]->changeMortage();
			}else if(improve > 0){
				AcademicBuilding *t = dynamic_cast<AcademicBuilding*>(Tiles[i]);
				for(int i; i < improve; ++i){
					t->improve();
				}
			}
		}
	}
}

void Data::save(std::ostream& os){
	os << static_cast<int>(getNoPlayers()) << "\n";
	os << current->printPlayer() << "\n";
	int finalPlayer = getNoPlayers() - 1;
	int nowPlayer = curPlayerNo();
	int i = nowPlayer + 1;
	//starts at curplayer, prints till last in vector, goes to front of vector,
	//	prints till curplayer
	while(true) {
		if (i == nowPlayer) {
			break;
		} else if (i <= finalPlayer) {
			os << players[i]->printPlayer() << "\n";
			if (i == finalPlayer) { i = 0;
			} else { ++i;}
		}
	}
	for (int i = 0; i <= 39; ++i) {
		os << Tiles[i]->getName() << " ";
		if(Tiles[i]->isPurchasable()) {
			os << Tiles[i]->getOwner();
	                if((Tiles[i]->getBlock() != "Gyms") &&(Tiles[i]->getBlock() != "Residences")){
			        os << " " << dynamic_cast<AcademicBuilding*>(Tiles[i])->getImpLevel();
			}
				//Tiles[i]->getImpLevel();
		} else {
			os << "BANK";
		}
		os << '\n';
	}
}

void Data::checkTile(int i){
	current->MovePosn_By(i);
	if(current->get_posn() > 39){
		OSAPcol();
		current->JumpTo_posn(current->get_posn() - 39);
	}
	std::cout << "Current Tile: " << Tiles[current->get_posn()]->getName() << std::endl;
	if(Tiles[current->get_posn()]->isPurchasable()){
		if(Tiles[current->get_posn()]->getOwner() == "BANK"){
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
			payRent();
		} 

	}else{
		std::cout << "Not purchasable tile." << std::endl;
		if(Tiles[current->get_posn()]->getName() == "GO TO TIMS"){
			std::cout << "going to jail" << std::endl;
			goTimsJail();
		}else if(Tiles[current->get_posn()]->getName() == "GOOSE NESTING"){

		}else if(Tiles[current->get_posn()]->getName() == "TUITION"){

		}else if(Tiles[current->get_posn()]->getName() == "COOP FEE"){

		}else if(Tiles[current->get_posn()]->getName() == "SLC"){
			//SLC();
		}else if(Tiles[current->get_posn()]->getName() == "NEEDLES HALL"){
			
		}
	}
	printBoard();
}

bool Data::buy(){
	if((current->get_balance()-Tiles[current->get_posn()]->getPurcahseCost()) < 0){
		std::cout << "Balance to low. Can't buy." << std::endl;
		return false;
	}
	std::cout << "Buying" << std::endl;
	Tiles[current->get_posn()]->setOwner(current->get_name());
	current->subMoney(Tiles[current->get_posn()]->getPurcahseCost());

	current->addProperty(current->get_posn());

	std::vector<int> prop = current->getProperties();
	return true;
}

void Data::payRent(){
	findOwedP(Tiles[current->get_posn()]->getOwner());
	std::cout << "You got to pay rent to " << owedPlayer->get_name() << "!"<< std::endl;
	int numOfProp = getNumProp(Tiles[current->get_posn()]->getBlock());
	std::cout << owedPlayer->get_name() << ": " << owedPlayer->get_balance() << std::endl;
	std::cout << current->get_name() << ": " << current->get_balance() <<std::endl;
	
	if((Tiles[current->get_posn()]->getBlock() == "Residences") || (Tiles[current->get_posn()]->getBlock() == "Gyms")){
		
		if(current->get_balance() >= Tiles[current->get_posn()]->getTuition(numOfProp)){

			current->subMoney(Tiles[current->get_posn()]->getTuition(numOfProp));
			owedPlayer->addMoney(Tiles[current->get_posn()]->getTuition(numOfProp));
		}else{
			bool t = forcePay(Tiles[current->get_posn()]->getTuition(numOfProp));\
			if(t == false){
				return;
			}
		}
	}else if(checksMonopoly(Tiles[current->get_posn()]->getName())){

		AcademicBuilding *tmp = dynamic_cast<AcademicBuilding*>(Tiles[current->get_posn()]);
		std::cout << "Being called" << std::endl;
		if(tmp->getImpLevel() == 0){
			if(current->get_balance() >= tmp->getTuition(0)*2 ){
				current->subMoney(tmp->getTuition(0)*2);
				owedPlayer->addMoney(tmp->getTuition(0)*2);
			}else{
				bool t = forcePay(tmp->getTuition(0)*2);
				if(t == false){
					return;
				}
			}
		}else{
			if(current->get_balance() >= tmp->getTuition(0) ){
				current->subMoney(tmp->getTuition(0));
				owedPlayer->addMoney(tmp->getTuition(0));
			}else{
				bool t = forcePay(tmp->getTuition(0));
				if(t == false){
					return;
				}
			}
		}

	}else{
		if(current->get_balance() >= Tiles[current->get_posn()]->getTuition(0)){
			current->subMoney(Tiles[current->get_posn()]->getTuition(0));
			owedPlayer->addMoney(Tiles[current->get_posn()]->getTuition(0));
		}else{
			bool t = forcePay(Tiles[current->get_posn()]->getTuition(0));
			if(t == true){
				return;
			}
		}
	}

	std::cout << "New Balances:" << std::endl;
	std::cout << owedPlayer->get_name() << ": " << owedPlayer->get_balance() << std::endl;
	std::cout << current->get_name() << ": " << current->get_balance() << std::endl;
}

int Data::getNumProp(std::string type){
	std::string block = Tiles[current->get_posn()]->getBlock();
	std::string	owner = Tiles[current->get_posn()]->getOwner();
	int numInMonopoly = 0;
	int numOwned = 0;
	for(int i = 0; i < Tiles.size(); ++i){
		if(Tiles[i]->getBlock() == block){
			++numInMonopoly;
			if(Tiles[i]->getOwner() == owner){
				++numOwned;
			}
		}
	}
	return numOwned;
}

void Data::improve(std::string property){
	if((Tiles[current->get_posn()]->getBlock() == "Gyms") || (Tiles[current->get_posn()]->getBlock() == "Residences")){
		std::cout << "This tile is not upgradable." << std::endl;
		return;
	}
	int index = ownsProperty(property);
	if (index >= 0){
		if(checksMonopoly(property) == false){
			std::cout << "You don't have a Monopoly on the set of " << Tiles[index]->getBlock() << ". Please buy all the properties in that Monopoly block before improving." << std::endl;
			return;
		}
		AcademicBuilding *tmp = dynamic_cast<AcademicBuilding*>(Tiles[index]);
		if((tmp->getImpLevel() < 5) && ((current->get_balance()-tmp->getImpCost()) > 0)){
			tmp->improve();
			current->subMoney(tmp->getImpCost());
			std::cout << tmp->getName() << " has " << tmp->getImpLevel() << " improvements." << std::endl;
		}else{
			std::cout << tmp->getName() << " currently at improve level " << tmp->getImpLevel() << ". Can't improve it, either maxed out or not enough funds." << std::endl;
		}
	}
	printBoard();
}

void Data::unimprove(std::string property){
	if((Tiles[current->get_posn()]->getBlock() == "Gyms") || (Tiles[current->get_posn()]->getBlock() == "Residences")){
		std::cout << "This tile can't be downgraded." << std::endl;
		return;
	}
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
	printBoard();
}

void Data::mortgage(std::string property){
	int index = ownsProperty(property);
	if(index == -1){
		return;
	}
	if(Tiles[index]->getBlock() != "Gyms" && Tiles[index]->getBlock() != "Residences"){
		if(checksMonopoly(property)){
			std::vector<int> tmp = propertiesOnMonopoly(Tiles[index]->getBlock());
			for(int i = 0; i < tmp.size(); ++i){
				AcademicBuilding *t = dynamic_cast<AcademicBuilding*>(Tiles[tmp[i]]);
				if(t->getImpLevel() > 0){
					std::cout << "Unimprove the properties on the block " << t->getBlock() << "." << std::endl;
					std::cout << "Following that action, you can mortgage " << Tiles[index]->getName() << "." << std::endl;
					return;
				}
			}
		}
	}
	if(index >= 0){
		BoardTiles *tmp = Tiles[index];
		if((tmp->getBlock() != "Gyms") &&(tmp->getBlock() != "Residences")){
			AcademicBuilding *t = dynamic_cast<AcademicBuilding*>(Tiles[index]);
			if(t->getImpLevel() > 0){
				std::cout << "There are " << t->getImpLevel() << " improvements. Unimprove before mortgaging " << tmp->getName() << "." << std::endl;
				return;
			}
		}
		if(tmp->getMortgage() != true){
			tmp->changeMortage();
			std::cout << current->get_balance() << std::endl;
			current->addMoney(tmp->getPurcahseCost()/2);
			std::cout << tmp->getName() << " mortgaged." << " New balance is " << current->get_balance() << "." << std::endl;
		}else{
			std::cout << tmp->getName() << " already mortgaged." << std::endl;
		}
	}
	printBoard();
}

void Data::unmortage(std::string property){
	int index = ownsProperty(property);
	if(index >= 0){
		BoardTiles *tmp = Tiles[index];
		if(tmp->getMortgage() != false){
			if(current->get_balance() < (tmp->getPurcahseCost()/0.6)){
				std::cout << "Don't have enough money. Need " << tmp->getPurcahseCost()/0.6 << std::endl;
				return;
			}
			tmp->changeMortage();
			current->subMoney(tmp->getPurcahseCost()*0.6);
			std::cout << tmp->getName() << " unmortgaged." << " New balance is " << current->get_balance() << "." << std::endl;
		}else{
			std::cout << tmp->getName() << " already unmortgaged." << std::endl;
		}
	}
	printBoard();
}

int Data::ownsProperty(std::string property){
	
	std::vector<int> tmpOwned = current->getProperties();
	for(int i = 0; i < static_cast<int>(tmpOwned.size()); ++i){
		if((Tiles[tmpOwned[i]]->isPurchasable() != false) && (Tiles[tmpOwned[i]]->getName() == property)){
			return tmpOwned[i];
		}
	}
	std::cout << "You don't own this property." << std::endl;
	return -1;
}

bool Data::checksMonopoly(std::string property){
	int index = getPropertyIndex(property);
	if(index <= 0){
		std::cout << "Not a property." << std::endl;
		return false;
	}
	std::string block = Tiles[index]->getBlock();
	std::string	owner = Tiles[index]->getOwner();
	int numInMonopoly = 0;
	int numOwned = 0;
	for(int i = 0; i < Tiles.size(); ++i){
		if(Tiles[i]->getBlock() == block){
			++numInMonopoly;
			if(Tiles[i]->getOwner() == owner){
				++numOwned;
			}
		}
	}

	if(numOwned == numInMonopoly){
		return true;
	}
	return false;
}

int Data::getPropertyIndex(std::string property){
	for(int i = 0; i < Tiles.size(); ++i){
		if(Tiles[i]->getName() == property){
			return i;
		}
	}
	std::cout << "Ran into error." << std::endl;
	return 0;
}

std::vector<int> Data::propertiesOnMonopoly(std::string block){
	std::vector<int> tmp;
	for(int i = 0; i < Tiles.size(); ++i){
		if(Tiles[i]->getBlock() == block){
			tmp.push_back(i);
		}
	}
	return tmp;
}

void Data::assets(){
	std::cout << current->get_name() << " " << current->get_piece() << " " << current->get_timsCups() << " " << current->get_balance() << " " << current->get_posn() << " ";
	if(current->get_posn() == 10){
		if(current->isInJail()){
			std::cout << current->isInJail() << " " << current->jailRollsCount();
		}else{
			std::cout << current->isInJail();	
		}
	}
	std::cout << std::endl;
	std::vector<int> tmpProp = current->getProperties();
	for(int i = 0; i < 0; ++i){
		std::cout << tmpProp[i] << std:: endl;
	}
	for(int i = 0; i < tmpProp.size(); ++i){
		std::cout << Tiles[tmpProp[i]]->getName() << " " << Tiles[tmpProp[i]]->getBlock() << std::endl	;
	}
}

bool Data::forcePay(int i){
	std::vector<int> tmp = current->getProperties();
	while(current->get_balance() < i){
		bool mort = false;
		for(int i = 0; i < tmp.size(); ++i){
			if(Tiles[i]->getMortgage()){
				mort = true;
			}
		}
		if(mort){
			std::cout << "Please mortgage and unimprove your properties to pay the debt. You can also decare bankruptcy." << std::endl;
			std::cout << "You commands are: " << std::endl;
			std::cout << "mortgage <property>" << std::endl;
			std::cout << "unimprove <property>" << std::endl;
			std::cout << "bankruptcy" << std::endl;
		}else{
			std::cout << "You have nothing else to raise to funds. The issuer of the credit will posses you are remaining assets." << std::endl;
			//bankrupt();
			return false;
		}
		std::string command;
		std::cin >> command;
		if(command == "mortgage"){
			std::cin >> command;
			mortgage(command);
		}else if(command == "unimprove"){
			unimprove(command);
		}else if(command == "bankruptcy"){
			//bankrupt()
			std::cout << "You have nothing else to raise to funds. The issuer of the credit will posses you are remaining assets." << std::endl;
			return false;
		}else{
			std::cout << "Invalid command. Must pay issuer." << std::endl;
		}

	}
	return true;
}
/*
void Data::bankrupt(std::string owedP){
	int mortPay = 0;
	std::vector<int> tmpProp = current->getProperties();
	if(owedP == "BANK"){
		for(int i = 0; i < tmpProb.size(); ++i){
			if(Tiles[tmpProp[i]]->getMortgage()){
				Tiles[tmpProp[i]]->changeMortage();
			}
			Tiles[tmpProp[i]]->setOwner() = "BANK";
		}

	}else{
		findOwedP(owedP);
		for(int i = 0; i < tmpProp.size(); ++i){
			owedPlayer->addProperty(tmpProp[i]);
			if(Tiles[tmpProp[i]->getMortgage()]){
				mortPay += (Tiles[tmpProp[i]]->getPurcahseCost()*0.1);
			}
			owedPlayer->addMoney(current->get_balance());
			if(owedPlayer->get_balance() - mortPay > 0){
				owedPlayer->subMoney(current->get_balance());
			}else{
				std::cout << "Not enough to funds to pay for mortgage." << std::endl;
			}
		}
	}
	current->subMoney(current->get_balance());
	owedP = nullptr;
}*/

void Data::findOwedP(std::string owedP){
	for(int i = 0; i < players.size(); ++i){
		if(owedP == players[i]->get_name()){
			owedPlayer = players[i];
		}
	}
}

bool Data::playerInJail() const{
	return current->isInJail();
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
	std::cout << "Passed go. " << current->get_balance() << " is the new balance." << std::endl;
	(*current).addMoney(200);
	std::cout << "Passed go. " << current->get_balance() << " is the new balance." << std::endl;
}
/*
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
}*/
/*
void Data::getRent(int i) const{

}

bool Data::auction(int i) const{
	std::vector<std::string> playersInAuction;
	std::vector<std::string> dropped;
	for(int i = 0; i < getNoPlayers(); ++i){
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
}

void Data::setPlayers(std::string name, char piece){
	players.push_back(new Player{name, piece});
}

void Data::getPlayerNames(){
	for(int i = 0; i < getNoPlayers(); ++i){
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
}
*/
