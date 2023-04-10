#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Data.h"

class Commands{
	Data *data = new Data;
	bool rolled;
	int player;
	int maxPlayer;
 public:
	Commands();
	~Commands();
	void initializeGame(std::string fileName);
	void save();
	void initializePlayers(int a);
	void roll(int i);
	 void next();
	 void trade ();
	 //note name refers to another player...whats your way of finding the right player?not sure if string is the right data type maybe we should passs a player??

	 void improve();
	 void mortage();
	 void unmortage();                                            
	 bool bankrupt();
	 void assets();
	 void all();
};

#endif
