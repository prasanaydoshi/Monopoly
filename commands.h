#ifndef _commands_h_
#define _commands_h_
#include <iostream>
#include <string>
#include "Data.h"

class Commands{
	Data *data = new Data;
 public:
	~Commands();
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

#endif _commands_h_
