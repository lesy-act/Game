#ifndef APP_H
#define APP_H
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

private:
    bool isRunning;
    static App* instance; // Singleton instance
    static SDL_Renderer* renderer; // Static renderer for the application
    static SDL_Window* window; // Static window for the application
    std::mutex mtx; // Mutex for thread safety

};

#endif // APP_H