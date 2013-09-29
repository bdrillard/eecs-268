/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: Translator.cpp
 * Date Created: 02/04/2013
 * Last Modified: 02/10/2013
 * Description: This file contains implementation of the
 * Translator class. It creates TranslationTables and decodes
 * messages
 */
#include "Translator.h"

//Generic constructor
Translator::Translator() {
}

/*
 * Precondition: an input file has been opened and passed from main
 * Postcondition: a pair of TranslationTables are created that will contain an
 * array of KeyValuePairs
 */
Translator::Translator(std::ifstream& input) {
        code = new TranslationTable<std::string, int>(input);
        cypher = new TranslationTable<int, std::string>(input);
}

/*
 * Precondition: two translation tables have been created and populated by key value
 * pairs from an opened input file
 * Postcondition: the decoded message is printed to the screen.
 */
void Translator::decode(std::ifstream& input) {
	std::string myKey;
	while(input >> myKey)
        	std::cout << cypher -> getValue(code -> getValue(myKey)) << ' ';
	std::cout << '\n';
}
