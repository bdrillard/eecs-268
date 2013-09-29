//Generic constuctor
template<typename Key, typename Value>
KeyValuePair<Key, Value>::KeyValuePair() {
}

//Constructor with parameters
template<typename Key, typename Value>
KeyValuePair<Key, Value>::KeyValuePair(Key key, Value item) {
	setPair(key, item);
}

//Set Key and Value to be either string or integer objects as collected from input file
template<typename Key, typename Value>
void KeyValuePair<Key, Value>::setPair(Key key, Value item) {
	pairKey = key;
	pairItem = item;
}

//Getter for Key
template<typename Key, typename Value>
Key KeyValuePair<Key, Value>::getKey() {
	return pairKey;
}

//Getter for Value
template<typename Key, typename Value>
Value KeyValuePair<Key, Value>::getValue() {
	return pairItem;
}
