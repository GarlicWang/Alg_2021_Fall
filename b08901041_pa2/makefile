CC=g++
CFLAGS = -c
# -c option ask g++ to compile the source files, but do not link.
# -O2 option is for optimized version
OPTFLAGS = -O2

all	: bin/mps
	@echo -n ""

bin/mps		: map.o
		$(CC) $(OPTFLAGS) map.o -o bin/mps
map.o		: src/map.cpp src/maxLine.h
		$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@ 

# clean all the .o and executable files
clean:
		rm -rf *.o bin/*
