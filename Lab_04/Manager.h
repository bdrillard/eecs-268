/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: Manager.h
 * Date Created: 2/24/13
 * Last Modified: 2/24/13
 * Description: This file contains the class declaration for the Manager,
 * which encapsulates a bag and provides methods to access it and its
 * values
 */
#ifndef _MNGR
#define _MNGR
#include "LinkedBag.h"
#include <cstddef>
#include <iostream>
#include <fstream>

class Manager {
	private:
		//String bag instance
		LinkedBag<std::string>* testBag;
	public:
		Manager();
		Manager(std::istream& input);
		virtual ~Manager();
		//Call gather, retrieve methods
		void start();
};
#endif		
