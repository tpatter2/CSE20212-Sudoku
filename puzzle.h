#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename P>	//templated class (P for PUZZLE)
class Puzzle{
   public:
	Puzzle(int = 9, P = 0);
	int size();
	void set(int, int, P);	//
	P get(int, int);	//gets value of puzzle cell
	bool checkComplete();	//checks for completed puzzle

	template<typename A>
	friend istream& operator>>(istream&, Puzzle<A>&); //reads puzzle from istream
	template<typename A>
	friend ostream& operator<<(ostream&, Puzzle<A>&);
	typedef vector< vector<P> > myBoard;
   private:
	myBoard board;
	P defVal;
	bool yContains(int, P);	//checks column for specific value
	bool xContains(int, P);	//checks row for specific value
	bool localContains(int, int, P); //check recursive box (3x3) contains specific value
};

template <typename P>
ostream& operator<<(ostream& output, Puzzle<P>& puzzle){
	//print puzzle element by element
	for (int x = 0; x < puzzle.size(); x++){
		for (int y = 0; y < puzzle.size(); y++){
			output << puzzle.board[x][y] << " ";
		}
		output << endl;
	}
return (output);
}

template <typename P>
Puzzle<P>::Puzzle(int size, P element){
	P temp;
	for( int x = 0; x<size; x++){
		vector<P> row(size, 0);
		board.push_back(row);
	}
	defVal = element;
}

template <typename P>
int Puzzle<P>::size(){
	return board.size();
}

template <typename P>
void Puzzle<P>::set(int x, int y, P value){
	if((x<size()) && (y<size()) && (x >= 0) && (y >= 0) && ((value == defVal) || (!yContains(y,value)) && (!xContains(x,value)) && !localContains(x, y, value))){
		board[x][y] = value;
	}
}

template <typename P>
P Puzzle<P>::get(int x, int y){
	if ((x < size()) && (y < size()) && (x >=0) && (y >= 0)){
		return board[x][y];
	}
	return 0;
}

template <typename P>
bool Puzzle<P>::checkComplete(){
	for(int x = 0; x < size(); x++){
		for(int y = 0; y < size(); y++){
			if (board[x][y] == defVal){
				return false;
			}
		}
	}
	return true;
}
/*
template <typename P>
bool Puzzle<P>::yContains(int y, P value){
	return !(find(board[y].begin(), board[y].end(), value)==board[y].end());
}*/

template <typename P>
bool Puzzle<P>::yContains(int y, P value){
	for(int x=0;x < size(); x++){
		if(board[x][y] == value){
			return true;
		}
	}
}

template <typename P>
bool Puzzle<P>::xContains(int x, P value){
	return !(find(board[x].begin(), board[x].end(), value)==board[x].end());
}

template <typename P>
bool Puzzle<P>::localContains(int x, int y, P value){
	int numBoxes = sqrt(size());
	int lx = x/ numBoxes*numBoxes;
	int ly = y/ numBoxes*numBoxes;

	return ((board[lx][ly] == value) || (board[lx][ly+1] == value) || (board[lx][ly+2]) ||
		(board[lx+1][ly] == value) || (board[lx+1][ly+1] == value) || (board[lx+1][ly+2]) ||
		(board[lx+2][ly] == value) || (board[lx+2][ly+1] == value) || (board[lx+2][ly+2]));
}

template <typename P>
istream& operator>>(istream& input, Puzzle<P>& puzzle){
	P value;
	for (int x = 0; x < puzzle.size(); x++){
		for (int y = 0; y < puzzle.size(); y++){
			input >> value;
			puzzle.board[x][y] = value;
		}
	}
	return (input);
}
#endif //PUZZLE_H
