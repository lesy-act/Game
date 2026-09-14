#ifndef CHARACTER_H 
#define CHARACTER_H

#include <iostream>

class ICharacter {
public:
    virtual void attack() = 0;
    virtual void defend() = 0;
    virtual ~ICharacter() = default;
};

#endif // CHARACTER_H