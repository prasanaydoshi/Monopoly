#include "Player.h"

// constructor
Player::Player(std::string name, char piece): name{name}, piece{piece},
        posn{0}, balance{1500}, timsCups{0} { }

// accessors
std::string Player::get_name() const { return name; }
char Player::get_piece() const { return piece; }
int Player::get_posn() const { return posn; }
int Player::get_balance() const { return balance; }
int Player::get_timsCups() const { return timsCups; }
int Player::No_ownedProperties() const { return owned.size(); }
int Player::get_TileNo(int i) const { return owned[i]; }

// mutators
void Player::JumpTo_posn(int a) { posn = a; 
//will mostly be need to be used with jail

}
void Player::MovePosn_By(int a) {
	posn += a;
	if (posn > 39) {
		posn = posn % 39;
        }
		//call go function and increment the player bal by 200
}

void Player::pay(int a) {
	balance += a;
}

void Player::buy(int a) {
	balance -= a;
}

//other methods
void Player::nextposn() {
	if (posn < 40) {
		++posn;
        } else {
                posn = 0;
        }
}

//int calc_NetWorth() {}

std::string Player::get_properties() {
	// TODO: implement this method
	return "";
}
