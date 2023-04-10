#include "Player.h"

// constructor
Player::Player(std::string name, char piece): name{name}, piece{piece},
        posn{0}, balance{1500}, timsCups{0}, inJail{false}, jailRolls{1}{}

Player::Player(std::string name, char piece, int posn, int balance, int timsCups, bool inJail, int jailRolls)
        :name{name}, piece{piece}, posn{posn}, balance{balance}, timsCups{timsCups}, inJail{inJail}, jailRolls{jailRolls}{}

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
	if (posn < 39) {
		++posn;
        } else {
                posn = 0;
        }
}

std::string Player::printPlayer() {      //
	std::string info = get_name() + " " + piece + " ";
        info += std::to_string(get_timsCups()) + " ";
	info += std::to_string(get_balance()) + " ";
        info += std::to_string(get_posn());
	if (get_posn() == 10) {
		if (inJail == true) {
			info += " 1 " + std::to_string(jailRolls);
		} else {
			info += "0";
		}
	}
	return info;
}

//int calc_NetWorth() {}
/*
std::string Player::get_properties() {
	// TODO: implement this method
	return "";
}
*/
