prog2: prog2.cpp minxmax.cpp minmax.h
	g++ -c prog2.cpp
	g++ -c minmax.cpp
	g++ prog2.o minmax.o -o prog2.out
