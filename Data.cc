#include "Data.h"
#include <random>


//constructor
Data::Data(): current{nullptr}, bank{nullptr} { }; //default

//nested accessors
std::string get_namePlayer(int i) { return *(players[i]).get_name(); };

char get_piecePlayer(int i) { return *(players[i]).get_piece(); };

int get_posPlayer(int i) { return *(players[i]).get_posn(); };

//non-purchasable tile methods
void Data::TuitionPay() {			//REQUIRES TRANSFER OF PROPERTIES OR TOTAL NETWORTH VAL
	if ( (*current).get_posn() == 24) {
	}
};

void Data::CoopFee() {
	if ( (*current).get_posn() == 18) {
		(*current).change_balance(-150);
	}
};

void Data::OSAPcol() {
	if ( (*current).get_posn() == 20) {
		(*current).change_balance(200);
	}
};

void Data::TimsJail() { 			//REQUIRES ROLL FUNCTION
	if ( (*current).get_posn() == 30) {
	}
};

void Data::GoToJail() {
	if ( (*current).get_posn() == 10) {
		(*current).JumpTo_posn(30);
	}
};

void Data::SLC() {
	if ( ( (*current).get_posn() == 13) || ( (*current).get_posn() == 13) ){
		std::random_device rd;
		std::mt19937 gen(rd());
		std::discrete_distribution<> d({1/8, 1/6, 1/6, 1/8, 1/6, 1/6, 1/24, 1/24})
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
};

void Data::NH() {
	if (( (*current).get_posn() == 2) || ( (*current).get_posn() == 16) ){
		std::random_device rd;
		std::mt19937 gen(rd());
		std::discrete_distribution<> d({1/18, 1/9, 1/6, 1/3, 1/6, 1/9, 1/18})
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
};

