/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: Point2DArray.cpp
 * Date Created: 02/12/13
 * Last Modified: 02/14/13
 * Description: This file contains the implementation for the 
 * Point2DArray class. Its private method reads a file and populates
 * the array. Its public methods allow for declaration of a 
 * Point2DArray object, printing of the points, and computation of
 * the centroid and length.
 */
#include "Point2DArray.h"

//Generic constructor
Point2DArray::Point2DArray() : numPoints(0), arraySize(0) {
}

/*
 * Precondition: filestream @input is opened and passed to the constructor
 * of a Point2DArray object
 * Postcondition: the @arraySize is gathered and set from the file and the file
 * is read by the @readPoints method
 */
Point2DArray::Point2DArray(std::istream& input) : numPoints(0) {
	input >> arraySize;
	pts = new Point2D[arraySize];
	readPoints(input);
}
//Destructor for Point2DArray
Point2DArray::~Point2DArray() {
	delete[] pts;
	pts = NULL;
}

/*
 * Precondition: filestream @input was opened and passed through the constructor
 * Postcondition: the Point2DArray @pts will be populated with (x,y) coordinates
 * from @input and @pts will be resized if necessary to accomodate more points
 */
void Point2DArray::readPoints(std::istream& input) {
	double pt1;
	double pt2;
	
	//Gather initial points
	input >> pt1;
	input >> pt2;
	//Start with arraySize check, create new if necessary, then assign points
	while(!input.eof()) {
		//This routine will increase the @arraySize to accomodate more points
		if(numPoints == arraySize) {
			arraySize *= 2;
			//Create new array for deep copy, delete old array and reset pointer to new array
			Point2D* newPts = new Point2D[arraySize];
			for(int i = 0; i < arraySize; i++) {
				newPts[i][0] = pts[i][0];
				newPts[i][1] = pts[i][1];
			}
			delete[] pts;
			pts = newPts;
			newPts = NULL;
		}
		
		//Set points to Point2D object, x followed by y
		pts[numPoints][0] = pt1;
		pts[numPoints][1] = pt2;
		
		//Increment running total of points, and gather next set
		numPoints++;
		input >> pt1;
		input >> pt2;
	} 
}
/*
 * Precondition: @pts contains a set of Point2D objects with 2 double values each
 * Postcondition: the centroid of the data set will be calculated and returned
 * as a pointer to a Point2D object
 */
Point2D* Point2DArray::centroid() {
	double sumX = 0;
	double sumY = 0;
	//Create container for the centroid point set
	Point2D* c = new Point2D[1];
	
	//Sum point components, then compute avarage
	for(int i = 0; i < numPoints; i++) {
		sumX += pts[i][0];
		sumY += pts[i][1];
	} 

	*c[0] = sumX / numPoints;
	*c[1] = sumY / numPoints;

	return c;
}

/*
 * Precondition: a populated Point2DArray exists
 * Postcondition: the length of the data set is computed
 */
double Point2DArray::length() {
	double length = 0;
	
	//Compute length by Euclidean distance
	for(int i = 0; i < numPoints-1; i++)
		length += std::sqrt(std::pow(pts[i+1][0] - pts[i][0], 2) + std::pow(pts[i+1][1] - pts[i][1], 2));
	
	return length;
}

/*
 * Precondition: a populated Point2DArray exists
 * Postcondition: the values of the Point2D objects of the array
 * will be printed
 */
void Point2DArray::print(std::ostream& output) {
	//Escape codes for table formatting, print each point in the list
	output << "x\r\ty" << std::endl;
	for(int i = 0; i < numPoints; i++) {
		output << pts[i][0] << "\r\t" << pts[i][1] << std::endl;
	}
}
/*
 * Precondition: a populated Point2DArray exists
 * Postcondition: any passed Point2D object will have its values printed.
 * We provide a separate method for this opposed to print or a routine in
 * centroid so that any Point2D object may hypothetically be printed
 */
void Point2DArray::displayPoint(Point2D* pt) {
	//Print dereferenced point to cout
	std::cout << *pt[0] << ' ' << *pt[1] << std::endl;
}
