#include "Data.h"

//constructor
Data::Data() { };  //needs finishing

//nested accessors


//non-purchasable tile methods
void Data::TuitionPay() {
		
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

};

void Data::GoToJail() {
	if ( (*current).get_posn() == 10) {
	}
};

void Data::SLC() {

};

void Data::NH() {

};

