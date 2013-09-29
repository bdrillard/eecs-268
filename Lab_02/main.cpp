/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: main.cpp
 * Date Created: 02/04/2013
 * Last Modified: 02/10/2013
 * Description: This file implements the Translator class.
 * A file stream is opened and passed to the created Translator
 * for decoding.
 */
#include "KeyValuePair.h"
#include "TranslationTable.h"
#include "Translator.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
	//Create and open file stream
	std::ifstream input;
	input.open(argv[1]);

	//Create translator, pass input, and decode
	Translator* myTranslator = new Translator(input);
	myTranslator -> decode(input);

	input.close();
	return 0;
}
