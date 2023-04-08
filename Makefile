Test: main.o board.o
	g++ main.o board.o data.o -o Test

main.o: main.cc board.h
	g++ -std=c++14 -c main.cc

board.o: board.cc board.h
	g++ -std=c++14 -c board.cc
	
data.o: Data.cc Data.h
	g++ -std=c++14 -c Data.cc

player.o: Player.cc Player.h
	g++ -std=c++14 -c Player.cc
