/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: Manager.cpp
 * Date Created: 02/12/13
 * Last Modified: 02/14/13
 * Description: this file contains the implementation of the 
 * Manager wrapper class for Point2DArray objects
 */
#include "Manager.h"

//Generic constructor
Manager::Manager() {
}

//Paramaterized constructor, creats Point2DArray from points in input
Manager::Manager(std::istream& input) {
	ptArray = new Point2DArray(input);
}

Manager::~Manager() {
	delete ptArray;
	ptArray = NULL;
}

/*
 * Precondition: a Point2DArray has been created and populated
 * Postcondition: Point2DArray methods will print the array composition,
 * its centroid, and its length
 */
void Manager::start() {
	std::cout << "Our collection of points is as follows:" << std::endl;
	ptArray -> print(std::cout);
	std::cout << "\nThe centroid is:" << std::endl;
	ptArray -> displayPoint(ptArray -> centroid());
	std::cout << "\nThe length of the points is:" << std::endl;
	std::cout << ptArray -> length() << std::endl;
}
