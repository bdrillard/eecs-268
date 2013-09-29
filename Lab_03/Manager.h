/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: Manager.h
 * Date Created: 02/12/13
 * Last Modified: 02/14/13
 * Description: this file contains the declaration for the
 * Manager class that wraps the Point2DArray class
 */
#ifndef _MNGR
#define _MNGR
#include "Point2DArray.h"

class Manager {
	private:
		//Pointer to Point2DArray
		Point2DArray* ptArray;
	public:
		Manager();
		Manager(std::istream& input);
		virtual ~Manager();
		void start();
};
#endif
