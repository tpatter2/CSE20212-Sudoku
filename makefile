all:	puzzle

puzzle:	puzzle.o
	   g++ puzzle.o -o puzzle

puzzle.o:	puzzle.cpp
	   g++ -c puzzle.cpp

clean:
	   rm -f *.o puzzle.cpp
