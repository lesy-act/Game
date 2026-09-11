#include<include/ICharacter.h>


class Player : public ICharacter {
public:
    void attack() override {
        std::cout << "Player attacks!" << std::endl;
    }

    void defend() override {
        std::cout << "Player defends!" << std::endl;
    }
};