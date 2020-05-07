//
// Created by Nicholas Hillier on 2020-04-26.
//
#pragma once
#ifndef C_PLUS_PLUS_PLAYGROUND_TWEETER_H
#define C_PLUS_PLUS_PLAYGROUND_TWEETER_H

#include "Person.h"
#include <string>

class Tweeter : public Person {

private:
    std::string twitterHandle;
public:
    Tweeter(std::string first, std::string last, int arbitrary, std::string handle);
    ~Tweeter();
    std::string GetName() const;
};


#endif //C_PLUS_PLUS_PLAYGROUND_TWEETER_H
