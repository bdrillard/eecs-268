/*
 * Name: Aleksander Eskilson, aleksanderesk@gmail.com
 * File Name: KeyValuePair.h
 * Date Created: 02/04/2013
 * Last Modified: 02/10/2013
 * Description: This file contains the template declaration and
 * implementation for KeyValuePair, which is an ordered pair of
 * string and integer objects.
 */
#ifndef _KEY_H_
#define _KEY_H_
#include <iostream>
#include <string>

template<typename Key, typename Value>
class KeyValuePair {
        private:
                Key pairKey;
                Value pairItem;
        public:
                KeyValuePair();
                KeyValuePair(Key key, Value item);
                void setPair(Key key, Value item);
                Key getKey();
                Value getValue();
};

#include "KeyValuePair.cpp"
#endif
