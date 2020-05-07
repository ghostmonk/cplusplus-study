//
// Created by Nicholas Hillier on 2020-04-27.
//

#ifndef C_PLUS_PLUS_PLAYGROUND_ACCUM_H
#define C_PLUS_PLUS_PLAYGROUND_ACCUM_H

template <class T>
class Accum {
private:
    T total;
public:
    explicit Accum(T start) : total(start) {};
    Accum<T> operator+=(const T &t) { total = total + t; return *this; }
    T GetTotal() const { return total; }
};


template <>
class Accum<Person> {
private:
    int total;
public:
    explicit Accum(const Person& person) : total(person.GetNumber()) {};
    int operator+=(Person const &t) { return total = total + t.GetNumber(); }
    int GetTotal() const { return total; }
};

#endif //C_PLUS_PLUS_PLAYGROUND_ACCUM_H
