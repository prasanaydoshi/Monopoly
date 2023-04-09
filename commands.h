#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <string>
#include <vector>
#include "Data.h"

class Commands{
	Data *data = new Data;
 public:
	Commands();
	~Commands();
	void initializePlayers(int a);
	 int roll() const;
	 void next() const;
	 void trade (std::string name, std::string give, std::string receive);
	 //note name refers to another player...whats your way of finding the right player?not sure if string is the right data type maybe we should passs a player??

	 void improve(std::string property, bool buy);
	 void mortage(std::string property);
	 void unmortage(std::string property);                                            
	 bool bankrupt();
	 void assets();
	 void all();
};

#endif