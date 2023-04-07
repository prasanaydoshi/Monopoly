#include "Data.h"

//constructor
Data::Data() { };  //needs finishing

//nested accessors
std::string get_namePlayer(int i) { return *(players[i]).get_name(); };

char get_piecePlayer(int i) { return *(players[i]).get_piece(); };

int get_posPlayer(int i) { return *(players[i]).get_posn(); };

//non-purchasable tile methods
void Data::TuitionPay() {
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

void Data::TimsJail() {
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
		int num_pick = rando();
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
	}
};

