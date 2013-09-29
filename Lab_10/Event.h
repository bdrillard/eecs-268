/*
 * Name: Aleksander Eskilson, aeskilson@ku.edu
 * File: Event.h
 * Created: 4/23/13
 * Modified: 5/8/13
 * Description: Class definition for Historical Event. Contains
 * private member variables for event date and description. 
 * Overloaded comparison operators included, as well as global
 * overloaded stream operators. 
 */
#ifndef _EVNT
#define _EVNT

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

class Event {
    private:
        int year;
        string description;
    public:
        void setYear(int aYear);
        void setDescription(string aDescription);
        int getYear() const;
        string getDescription() const;

        bool operator<(const Event& ev) const;
        bool operator>(const Event& ev) const;
        bool operator==(const Event& ev) const;
        bool operator<(int someYear) const;
        bool operator>(int someYear) const;
        bool operator==(int someYear) const;
};

#endif

//Global stream operators
std::istream& operator>>(std::istream& is, Event& ev);
std::ostream& operator<<(std::ostream& os, const Event& ev);
