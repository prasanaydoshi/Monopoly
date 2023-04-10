#ifndef _VIEW_H_
#define _VIEW_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <cstring>

int getNoPlay();
char charRep(int x);
void add_spaces(std::vector <std::string>& coord_spaces);
void join(int start, int end, std::vector <std::string> coord_join);
void semi_main();
void PrintBoard();

std::ostream& DisplayNames(std::ostream& os);
std::ostream& ShowInfo(std::ostream& os);
std::ostream& prog_messages(std::ostream& os);
std::ostream& menu(std::ostream& os);
std::ostream& MakeAction(std::ostream& os);
std::ostream& cur_assets(std::ostream& os);
std::ostream& all_assets(std::ostream& os);

#endif
