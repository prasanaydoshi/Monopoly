#ifndef _COMMANDS_H
#define _COMMANDS_H

#include <iostream>
#include <string>
#include "Data.h"

class Commands{
	Data *data;
 public:
	Commands::Commands();
	int roll() const;
	void next() const;
	void trade (std::string name, std::string give, std::string receive);
	//note name refers to another player...whats your way of finding the right player?not sure if string is the right data type maybe we should passs a player??

	void improve(std::string property, bool buy);
	void mortgage(std::string property);
	void unmortgage(std::string property);                                            
	bool bankrupt();
	void assets();
	void all();
};

#endif
