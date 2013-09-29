#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "FunMaze.h"

/*
 * Precondition: a two dimensional array has been populated with the constituents of a maze and the starting
 * coordinates have been passed as arguments
 * Postcondition: each solution to the maze will be found recursively and the solution will be printed
 * using the printMaze function. 
 */
void FunMaze::solveMaze(int x, int y) {
	//Determine if the current position is open (' ')
	if(maze[x][y] == ' ') {
		//If so, mark the position as visited with (0)
		maze[x][y] = '0';
	}

	//Check to see if we've currently arrived at the end (X), one of the base cases
	if(maze[x][y] == 'X') {
		//If so, print the maze and end the stack frame
		printMaze();
		return;
	}

	//Check each surrounding space, if the space is open (' ') or is the end marker (X), recurse over to that positions coordinates
	//Check up
	if(maze[x][y+1] == ' ' || maze[x][y+1] == 'X') {
		solveMaze(x, y+1);
		maze[x][y] = '0';
	}
	//Check down
	if(maze[x][y-1] == ' ' || maze[x][y-1] == 'X') {
		solveMaze(x, y-1);
		maze[x][y] = '0';
	}
	//Check right
	if(maze[x+1][y] == ' ' || maze[x+1][y] == 'X') {
		solveMaze(x+1, y);
		maze[x][y] = '0';
	}
	//Check left
	if(maze[x-1][y] == ' ' || maze[x-1][y] == 'X') {
		solveMaze(x-1, y);
		maze[x][y] = '0';
	}

	//If all paths from from this space have been exhausted, unmakr the position with an open space (' '), this allows us to backtrack from deadends
	maze[x][y] = ' ';

	//Returning from a dead end marks a base case, backtrack through stack frames to next path
	return;

}

//Constructor
FunMaze::FunMaze()
{
	maze = NULL;
	dim1 = 0;
	dim2 = 0;
}

//Destructor
FunMaze::~FunMaze()
{
	//free all memory we allocated earlier
	if(maze != NULL) {
		for(int i = 0; i < dim1; i++)
			delete[] maze[i];
		delete[] maze;
	}
}

//Reads the input file and stores the maze in an mxn array 
void FunMaze::readMaze(char* fileName)
{
	ifstream file;
	file.open(fileName, ios::in);
	string dummyLine;

	//check that we correctly opened the file
	if(!file) {
		cout << "Unable to open file" << endl;
		exit(1);
	}

	//get the dimensions of the maze
	file >> dim1;
	file >> dim2;

	//place the file get pointer at the beginning of the file
	file.seekg(ios::beg);
	
	//skip over the first line
	std::getline(file, dummyLine);

	//allocate memory for the maze
	//read in at the same time
	maze = new char*[dim1];
	for(int i = 0; i < dim1; i++){
		maze[i] = new char[dim2];
		file.getline(maze[i], dim2+1);	
	}

}

/*
 * Precondition: a two dimensional maze has been populated and passed to the solveMaze function
 * Postcondition: the current state of the maze will be printed
 */
void FunMaze::printMaze()
{
  //Iterate over each row and column, print the character at that index
  for(int i = 0; i < dim1; i++) {
	for(int j = 0; j < dim2; j++)
		cout << maze[i][j];
	cout << endl;
  }
}

	
