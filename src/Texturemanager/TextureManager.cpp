#include "Texturemanager/TextureManager.h"

TextureManager* TextureManager::instance = nullptr; // Initialize the singleton instance
std::mutex TextureManager::mtx; // Initialize the mutex for thread safety
TextureManager::TextureManager() {
    // Private constructor for singleton
}
void TextureManager::init(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

TextureManager* TextureManager::getInstance() {
    std::lock_guard<std::mutex> lock(mtx); // Lock the mutex for thread safety
    if (!instance) {
        instance = new TextureManager();
    }
    return instance;
}

SDL_Texture* TextureManager::loadTexture(const std::string& id, const char* filePath, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(filePath);
    if (!surface) {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    // Implementation for loading texture
    std::lock_guard<std::mutex> lock(this->mtx); // Lock the mutex for thread safety
    SDL_Texture* texture = IMG_LoadTexture(renderer, filePath);
    if (texture) {
        textureMap[id] = texture;
        textureList.push_back(texture);
    }
    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::draw(std::string id, SDL_Renderer* renderer, int x, int y, int width, int height) {
    // Implementation for drawing texture
    std::lock_guard<std::mutex> lock(this->mtx); // Lock the mutex for thread safety
    SDL_Rect destRect = { x, y, width, height };
    SDL_RenderCopy(renderer, textureMap[id], nullptr, &destRect);
}

void TextureManager::drawframe(std::string id, SDL_Renderer* renderer, int x, int y, int width, int height, int currentRow, int currentFrame) {
    std::lock_guard<std::mutex> lock(this->mtx); // Lock the mutex for thread safety
    SDL_Rect srcRect = { currentFrame * width, currentRow * height, width, height };
    SDL_Rect destRect = { x, y, width, height };
    SDL_RenderCopy(renderer, textureMap[id], &srcRect, &destRect);
}