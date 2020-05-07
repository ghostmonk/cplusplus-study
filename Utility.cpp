//
// Created by Nicholas Hillier on 2020-04-26.
//

#include "Utility.h"

bool IsPrime(int x) {
    for(int i = 2; i <= x/i; i++) {
        int factor = x/i;
        if(x == i*factor) {
            return false;
        }
    }
    return true;
}

 bool Is2MorePrime(int x) {
    int added = x + 2;
    return IsPrime(added);
}