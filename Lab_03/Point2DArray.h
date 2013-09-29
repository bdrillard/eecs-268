/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: Point2DArray.h
 * Date Created: 02/12/13
 * Last Modified: 02/14/13
 * Description: This file contains the class declaration
 * for a Point2DArray, which consists of an unordered collection
 * of Point2D objects that themselves contain an ordered pair of
 * doubles. 
 */
#ifndef _P2DA
#define _P2DA
#include <iostream>
#include <fstream>
#include <cmath>
//Define what a Point2D is
typedef double Point2D[2];

class Point2DArray {
	private: 
		//Pointer to Point2DArray
		Point2D* pts;
		//Current size of Point2DArray
		int arraySize;
		//Current number of points in the array
		int numPoints;
		//See implementation for method descriptions
		void readPoints(std::istream& input);
	public:
		Point2DArray();
		Point2DArray(std::istream& input);
		virtual ~Point2DArray();
		Point2D* centroid();
		double length();
		void print(std::ostream& output);
		void displayPoint(Point2D* pt);

};
#endif
