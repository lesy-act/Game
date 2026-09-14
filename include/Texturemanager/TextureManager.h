#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SDL2/SDL.h>
#include <mutex>
#include <map>
#include <vector>
#include <iostream>
#include <SDL2/SDL_image.h>

    
class TextureManager {
public:
    static std::mutex mtx; // Mutex for thread safety
private:
    static TextureManager* instance; // Singleton instance
    TextureManager(); // Private constructor for singleton
    std::map<std::string, SDL_Texture*> textureMap; // Map to store loaded textures
    std::vector<SDL_Texture*> textureList; // Vector to store all loaded textures
    SDL_Renderer* renderer; // Renderer for drawing textures
public:
    void init(SDL_Renderer* renderer); // Initialize the TextureManager with a renderer
    static TextureManager* getInstance(); // Get the singleton instance
    SDL_Texture* loadTexture(const std::string& id, const char* filePath, SDL_Renderer* renderer);
    void draw(std::string id, SDL_Renderer* renderer, int x, int y, int width, int height);
    void drawframe(std::string id, SDL_Renderer* renderer, int x, int y, int width, int height, int currentRow, int currentFrame);
};
#endif // TEXTUREMANAGER_H