#include <iostream>
#include <cstdlib>
#include "puzzle.h"
#include <fstream>
#define GAME_SIZE 9
using namespace std;

int main(int argc, char** argv){
	string fname;
	if(argc == 2){
		fname = argv[1];
	}else{
		cout<<"Please enter the input file: ";
		cin>> fname;
	}

	ifstream file(fname.c_str());
	if (!file.is_open()){
		cout << "File Failed to open " << fname << endl;
		return 1;
	}

	Puzzle<int> puzzle(GAME_SIZE,0);
	file >> puzzle;
	file.close();

	int x,y,value;
	while (!puzzle.checkComplete()){
		system("clear");
		cout<<"This is a simple sudoku puzzle, please press -1 when you want to quit"<< endl;
		cout<<puzzle;

		cout<<"Enter row, column and value [1-" << GAME_SIZE<<"] seperated by spaces: ";
		cin >> x;

		if(x==-1){
			break;
		}

		cin >> y >> value;
		puzzle.set(x-1, y-1, value);
	}
	return 0;
}
