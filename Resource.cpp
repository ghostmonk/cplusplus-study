//
// Created by Nicholas Hillier on 2020-04-27.
//

#include "Resource.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

Resource::Resource(string name) : name(name){
    cout << "Constructing " << name << endl;
}

Resource::~Resource(void) {
    cout << "Deconstructing " << name << endl;
}