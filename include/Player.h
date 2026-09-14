#ifndef PLAYER_H
#define PLAYER_H

#include "Character/ICharacter.h"
#include "Entity/Entity.h"
#include "Texturemanager/TextureManager.h"
#include "App/App.h"
#include <mutex>

class Player : public ICharacter, public Entity {
public:
    Player(Properties props = { {100, 100}, {128, 128}, 0 }); // Constructor with default properties
    void init();
    void render();
    void attack() override; // Implement attack method from ICharacter
    void defend() override; // Implement defend method from ICharacter
    static Player* getInstance();
private:
    // Add any private member variables or methods specific to the Player class here
    // static const int PLAYER_WIDTH = 128; // Example width for the player
    // static const int PLAYER_HEIGHT = 128; // Example height for the player   
    // static const int PLAYER_X = 100; // Example X position for the player
    // static const int PLAYER_Y = 100; // Example Y position for the player   
    static Player* instance; // Singleton instance of Player
private:
    static std::mutex mtx; // Mutex for thread safety
    SDL_Texture *playerTexture; // Texture for the player
};

#endif // PLAYER_H