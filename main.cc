#include <iostream>
#include <string>
#include <vector>
#include "Data.h"

using namespace std;

int main(){

	Data *test = new Data;

	test->printBlock();

	delete test;

}
