#include "Player.h"

// constructor
Player::Player(std::string name, char piece): name{name}, piece{piece},
        posn{0}, balance{1500}, timsCups{0}, inJail{false}, jailRolls{1}{}

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

std::vector<int> Player::getProperties() const{
        return owned;
}

bool Player::isInJail() const{
        return inJail;
}

int Player::jailRollsCount() const{
        return jailRolls;
}

//mutators
void Player::JumpTo_posn(int a){
        posn = a;
}

void Player::MovePosn_By(int a){
        posn += a;
}

void Player::subMoney(int a){
        balance -= a;
}

void Player::addMoney(int a){
        balance += a;
}

void Player::addProperty(int a){
        owned.push_back(a);
}

void Player::setInJail(){
        if(inJail){
                inJail = false;
                jailRolls = 1;
        }else{
                inJail =true;
        }
}

bool Player::setJailRolls(){
        ++jailRolls;
        if(jailRolls >= 3){
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
/*
std::string Player::get_properties() {
	// TODO: implement this method
	return "";
}
*/