//
// Created by Nicholas Hillier on 2020-04-26.
//
#pragma once
#ifndef C_PLUS_PLUS_PLAYGROUND_PERSON_H
#define C_PLUS_PLUS_PLAYGROUND_PERSON_H

#include <string>
#include <memory>
#include "Resource.h"

class Person {

private:
    std::string firstName;
    std::string lastName;
    int arbitraryNumber;
    std::shared_ptr<Resource> pResource;

public:
    Person(std::string first, std::string last, int arbitrary);
    Person();
    virtual std::string GetName() const;
    int GetNumber() const { return arbitraryNumber; }
    void SetNumber(int num) { arbitraryNumber = num; }
    void SetFirstName(std::string name) {firstName = name;}
    void AddResource();
    std::string GetResourceName() const { return pResource ? pResource->GetName() : ""; }
    bool operator>(int num) const;
    bool operator>(const Person& person) const;
    bool operator<(const Person& person) const;
    bool operator<(int num) const;
};

bool operator>(int num, Person& person);
bool operator<(int num, Person& person);

#endif //C_PLUS_PLUS_PLAYGROUND_PERSON_H
