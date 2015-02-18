#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <deque>
using namespace std;

template <typename P>	//templated class (S for PUZZLE)
class Puzzle{
   public:
	Puzzle<P>();
   private:
	deque<P> elements;
};

#endif //PUZZLE_H
