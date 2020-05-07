//
// Created by Nicholas Hillier on 2020-04-27.
//

#ifndef C_PLUS_PLUS_PLAYGROUND_RESOURCE_H
#define C_PLUS_PLUS_PLAYGROUND_RESOURCE_H
#import<string>

class Resource {
private:
    std::string name;
public:
    Resource(std::string name);
    ~Resource(void);
    std::string GetName() { return name; }
};


#endif //C_PLUS_PLUS_PLAYGROUND_RESOURCE_H
