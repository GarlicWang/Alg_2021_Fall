CC=g++
CFLAGS = -c
# -c option ask g++ to compile the source files, but do not link.
# -O2 option is for optimized version
OPTFLAGS = -O3

all	: bin/cb
	@echo -n ""

bin/cb		: main.o undirected.o directed.o
		$(CC) $(OPTFLAGS) main.o undirected.o directed.o -o bin/cb
main.o		: src/main.cpp src/header.h
		$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@ 
undirected.o		: src/undirected.cpp src/header.h
		$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@ 
directed.o		: src/directed.cpp src/header.h
		$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@ 
# clean all the .o and executable files
clean:
		rm -rf *.o bin/*
