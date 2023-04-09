#include "Player.h"

// constructor
Player::Player(std::string name, char piece): name{name}, piece{piece},
        posn{0}, balance{1500}, timsCups{0}, inJail{inJail}{}

//acessors
std::string Player::get_name() const{
        return name;
}

char Player::get_piece() const{
        return piece;
}

int Player::get_posn() const{
        return posn;
}

int Player::get_balance() const{
        return balance;
}

int Player::get_timsCups() const{
        return timsCups;
}

//mutators
void Player::JumpTo_posn(int a){
        posn = a;
}

void Player::MovePosn_By(int a){
        posn += a;
}

void Player::pay(int a){
        balance += a;
}

void Player::buy(int a){
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
