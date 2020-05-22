prog2: prog2.o minmax.o
	CMAKE_CXX_FLAGS:STRING=-fPIC
	g++ prog2.o minmax.o -o prog2.out
	
