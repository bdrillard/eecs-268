/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: main.cpp
 * Date Created: 02/12/13
 * Last Modified: 02/14/13
 * Description: this file implements the Manager class that acts
 * as a wrapper for individual Point2DArrays, that themselves contain
 * a list of coordinate pairs
 */
#include "Point2DArray.h"
#include "Manager.h"
#include <iostream>
#include <fstream>
#include <cmath>

int main(int argc, char* argv[]) {
	//Open input file stream
	std::ifstream input;
	input.open(argv[1]);

	//Create Manager, run its methods to print the points,
	//the centroid, and the length
	Manager mgr(input);
	mgr.start();
	
	input.close();
	return 0;
}
