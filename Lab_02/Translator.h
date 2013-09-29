/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: Translator.h 
 * Date Created: 02/04/2013
 * Last Modified: 02/10/2013
 * Description: This file contains the declaration for the Translator
 * class. It contains declares TranslationTables for the code and cypher
 * and declares methods to create the Tables and decode a message from an
 * input file
 */
#ifndef _TRANS_H_
#define _TRANS_H_
#include "TranslationTable.h"
#include "KeyValuePair.h"

class Translator {
	private:
		//Declare table for our set of code words and their keys
		TranslationTable<std::string, int>* code;
		TranslationTable<int, std::string>* cypher;	
	public:
		Translator();
		Translator(std::ifstream& input);
		void decode(std::ifstream& input);
};

#endif
