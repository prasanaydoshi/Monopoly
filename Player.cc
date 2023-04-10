#include "Player.h"

// constructor
Player::Player(std::string name, char piece): name{name}, piece{piece},
        posn{0}, balance{1500}, timsCups{0}, inJail{false}, jailRolls{1} { }

// accessors
std::string Player::getName() const { return name; }
char Player::getPiece() const { return piece; }
int Player::getPosn() const { return posn; }
int Player::getBalance() const { return balance; }
int Player::getTimsCups() const { return timsCups; }
std::vector<int> Player::getProperties() const { return owned; }
bool Player::isInJail() const { return inJail; }
int Player::jailRollsCount() const { return jailRolls; }
//int Player::No_ownedProperties() const { return owned.size(); }
//int Player::get_TileNo(int i) const { return owned[i]; }

// mutators
void Player::jumpToPosn(int a) { posn = a; }
}

void Player::movePosnBy(int a) {
	posn += a;
	if (posn > 39) {
		posn = posn % 39;
        }
		//call go function and increment the player bal by 200
}

void Player::subMoney(int a) { balance -= a; }

void Player::addMoney(int a) { balance += a; }

void Player::addPropery(int a) { owned.push_back(a); }

void Player::setInJail() {
	if (inJail) {
		inJail = false;
		jailRolls = 1;
	} else {
		inJail = true;
	}
}

bool Player::setJailRolls() {
	++jailRolls;
	if (jailRolls >= 3) {
		return true;
	}
	return false;
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

//std::string Player::get_properties() {
	// xxTODO: implement this method
//	return "";
//}
