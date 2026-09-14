#ifndef APP_H
#define APP_H
#include "Texturemanager/TextureManager.h"
#include "Player.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <mutex>


class App {
public:
    App();
    ~App();
    void run();
    void init();
public:
    void handleEvents(SDL_Event& event);
    void update();
    void render();
    static App* getInstance();
    SDL_Renderer* getRenderer() const { return renderer; } // Getter for the renderer
    SDL_Window* getWindow() const { return window; } // Getter for the window

private:
    bool isRunning;
    static std::mutex mtx; // Mutex for thread safety
    static App* instance; // Singleton instance
    static SDL_Renderer* renderer; // Static renderer for the application
    static SDL_Window* window; // Static window for the application

};

#endif // APP_H