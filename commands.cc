#include "commands.h"

Commands::~Commands(){
    delete data;
}

int Commands::roll() const{

}

void Commands::next() const{

}

void Commands::trade(std::string name, std::string give, std::string receive){

}

void Commands::improve(std::string property, bool buy){

}

void Commands::mortage(std::string property){

}

void Commands::unmortage(std::string property){

}

bool Commands::bankrupt(){

}

void Commands::assets(){

}

void Commands::all(){

}