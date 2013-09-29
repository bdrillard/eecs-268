//Generic constructor
template<typename Key, typename Value>
TranslationTable<Key, Value>::TranslationTable() {
}

//Destructor for TranslationTable
template<typename Key, typename Value>
TranslationTable<Key, Value>::~TranslationTable() {
	//Delete the keyPairs array
	delete[] keyPairs;
	keyPairs = NULL;	
}

//Constructor with input file parameter, creates a TranslationTable
template<typename Key, typename Value>
TranslationTable<Key, Value>::TranslationTable(std::ifstream& input) {
	createTable(input);
}

/*
 * Precondition: an input file and Translator object have been created
 * and the input file has been passed
 * Postcondition: an array will be populated by KeyValuePairs
 */
template<typename Key, typename Value>
void TranslationTable<Key, Value>::createTable(std::ifstream& input) {
	//Gather number of pairs from first line of each set of data
	input >> numPairs;

	//Declare array and populate
	keyPairs = new KeyValuePair<Key, Value>[numPairs];
	for(int i = 0; i < numPairs; i++) {
		input >> key;
		input >> value;
		keyPairs[i].setPair(key, value);
	}
}

/*
 * Precondition: two arrays of KeyValuePairs have been created, and a key
 * from the first array has been passed
 * Postcondition: the corresponding value from the second array will be passed
 * as matched to the key
 */
template<typename Key, typename Value>
Value TranslationTable<Key, Value>::getValue(Key myKey) {
	for(int i = 0; i < numPairs; i++) {
		if(myKey == keyPairs[i].getKey())
			return keyPairs[i].getValue();
	}
}
