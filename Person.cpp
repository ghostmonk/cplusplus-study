//
// Created by Nicholas Hillier on 2020-04-26.
//
#include "Person.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

Person::Person(string first, string last, int arbitrary)
    : firstName(first), lastName(last), arbitraryNumber(arbitrary) {
    cout << "Constructing Person " << GetName() << endl;
}

Person::Person() : arbitraryNumber(0) {
    cout << "Default " << GetName() << arbitraryNumber << endl;
}

string Person::GetName() const {
    return firstName + " " + lastName;
}

void Person::AddResource() {
    pResource.reset();
    pResource=std::make_shared<Resource>(GetName());
}

bool Person::operator>(int num) const {
    return arbitraryNumber > num;
}

bool Person::operator>(const Person &person) const {
    return arbitraryNumber > person.arbitraryNumber;
}

bool Person::operator<(int num) const {
    return arbitraryNumber < num;
}

bool Person::operator<(const Person &person) const {
    return arbitraryNumber < person.arbitraryNumber;
}

bool operator>(int num, Person &person) {
    return num > person.GetNumber();
}

bool operator<(int num, Person &person) {
    return num < person.GetNumber();
}
