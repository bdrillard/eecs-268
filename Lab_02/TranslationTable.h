/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: TranslationTable.h
 * Date Created: 02/04/2013
 * Last Modified: 02/10/2013
 * Description: This file contains the template declaration and
 * implementation for TranslationTable, which creates arrays of 
 * KeyValuePairs from the input file and acquires the matching 
 * value of a passed key.
 */
#ifndef _TRANT_H_
#define _TRANT_H_
#include <iostream>
#include <fstream>
#include <string>
#include "KeyValuePair.h"

template<typename Key, typename Value>
class TranslationTable {
	private:
		int numPairs;
		Key key;
		Value value;
		KeyValuePair<Key, Value>* keyPairs;

	public:
		TranslationTable();
		~TranslationTable();
		TranslationTable(std::ifstream& input);
		void createTable(std::ifstream& input);
		Value getValue(Key myKey);
};
#include "TranslationTable.cpp"
#endif
