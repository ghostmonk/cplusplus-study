//
// Created by Nicholas Hillier on 2020-04-26.
//
#include "Tweeter.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

Tweeter::Tweeter(string first, string last, int arbitrary, string handle) :
    Person(first, last, arbitrary),
    twitterHandle(handle){
    cout << "Constructing Tweeter " << twitterHandle << endl;
}

Tweeter::~Tweeter() {
    cout << "Deconstructing Tweeter " << twitterHandle << endl;
}

std::string Tweeter::GetName() const {
    return Person::GetName() + twitterHandle;
}
