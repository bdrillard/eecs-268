/*
 * Name: Aleksander Eskilson, aeskilson@ku.edu
 * File: Event.cpp
 * Created: 4/23/13
 * Modified: 5/8/13
 * Description: Implementation for Event class. Global
 * stream operators implemented at bottom
 */
#include "Event.h"

//Setters
void Event::setYear(int aYear) {
    year = aYear;
}

void Event::setDescription(string aDescription) {
    description = aDescription;
}

//Getters
int Event::getYear() const {
    return year;
}

string Event::getDescription() const {
    return description;
}

//Relational operators
bool Event::operator<(const Event& ev) const {
    return year < ev.year;
}

bool Event::operator>(const Event& ev) const {
    return year > ev.year;
}

bool Event::operator==(const Event& ev) const {
    return year == ev.year;
}

bool Event::operator<(const int someYear) const {
    return year < someYear;
}

bool Event::operator>(const int someYear) const {
    return year > someYear;
}

bool Event::operator==(const int someYear) const {
    return year == someYear;
}

//Global stream operators
std::istream& operator>>(std::istream& is, Event& ev) {
    int year;
    string description;

    //Get whole remainder of line for description
    is >> year;
    getline(is, description);

    //Set
    ev.setYear(year);
    ev.setDescription(description);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Event& ev) {
    os << "Event for the year " << ev.getYear() << ":" << endl;
    os << "\t" << ev.getDescription() << endl;
    return os;
}
