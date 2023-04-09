Test: main.o board.o Data.o Player.o
	g++ main.o board.o Data.o Player.o -g -o Test

main.o: main.cc board.h
	g++ -std=c++14 -c main.cc

board.o: board.cc board.h
	g++ -std=c++14 -c board.cc
	
Data.o: Data.cc Data.h
	g++ -std=c++14 -c Data.cc

Player.o: Player.cc Player.h
	g++ -std=c++14 -c Player.cc
