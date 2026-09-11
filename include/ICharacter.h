#include<iostream>
class ICharacter {
public:
    virtual void attack() = 0; // Pure virtual function for attack
    virtual void defend() = 0; // Pure virtual function for defend
    virtual ~ICharacter() = default; // Virtual destructor
};