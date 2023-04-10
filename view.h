#ifndef _VIEW_H
#define _vIEW_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <cstring>

//int getNoPlay();
//char charRep(int x);
int add(int a, int b){ return a + b;}
void add_spaces(std::vector <std::string>& coord_spaces);
void join(int start, int end, std::vector <std::string> coord_join);
void semi_main(std::vector<int> imp, std::vector<int> getPos, std::vector<char> get_char);
//void PrintBoard();

//std::ostream& DisplayNames(std::ostream& os);
//std::ostream& ShowInfo(std::ostream& os);
//std::ostream& prog_messages(std::ostream& os);
//std::ostream& menu(std::ostream& os);
//std::ostream& MakeAction(std::ostream& os);
//std::ostream& cur_assets(std::ostream& os);
//std::ostream& all_assets(std::ostream& os);

#endif
