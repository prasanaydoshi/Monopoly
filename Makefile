Test: main.o board.o
	g++ main.o data.o board.o player.o -o Test

main.o: main.cc board.h
	g++ -std=c++14 -c main.cc

data.o: data.cc data.h
	g++ -std=c++14 -c data.cc

board.o: board.cc board.h
	g++ -std=c++14 -c board.cc

player.o: player.cc player.h
	g++ -std=c++14 -c player.cc
