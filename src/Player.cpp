#include"Player.h"

Player* Player::instance = nullptr;
std::mutex Player::mtx; // Initialize the mutex for thread safety
Player::Player(Properties props) : Entity(props) {
    // Constructor implementation
    playerTexture = nullptr; // Initialize playerTexture to nullptr
    frameCount = 0; // Initialize frameCount to 0
}

Player* Player::getInstance() {
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex for thread safety
    if (!instance) {
        instance = new Player();
    }
    return instance;
}

void Player::init() {
    TextureManager* textureManager = TextureManager::getInstance();
  //  textureManager->loadTexture("player", "assets/Idle.png", App::renderer); // Load player texture
    playerTexture = textureManager->loadTexture("player", "assets/Idle.png", App::getInstance()->getRenderer()); // Load player texture
}
void Player::render() {
    int currentTime = SDL_GetTicks();
    if (currentTime - lastFrameTime >= 100) { // Update frame every 100 milliseconds
        TextureManager::getInstance()->drawframe("player", App::getInstance()->getRenderer(), this->getPosition().x, this->getPosition().y, this->getSize().width, this->getSize().height,1,frameCount++);// Example position and size   
        frameCount++;
        lastFrameTime = currentTime;
    }
    if (frameCount >= 6) { // Assuming 4 frames for the player animation
        frameCount = 0; // Reset frame count after reaching the last frame
    }
}   

void Player::attack() {
    // Implement attack logic here
    std::cout << "Player attacks!" << std::endl;
}
void Player::defend() {
    // Implement defend logic here
    std::cout << "Player defends!" << std::endl;
}
