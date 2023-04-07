#ifndef _commands_h_
#define _commands_h_
#include <iostream>
#include <string>

class Commands{
 public:
	 int roll() const;
	 void next() const;
	 void trade (std::string name, std::string give, std::string receive);
	 void improve(std::string property, bool buy);
	 void mortage(std::string);
	 void unmortage(std::string);
	 bool bankrupt();
	 void assets();
	 void all();
};

#endif _commands_h_
