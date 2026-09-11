#include "App.h"    

App* App::instance = nullptr;
SDL_Renderer* App::renderer = nullptr;
SDL_Window* App::window = nullptr;

App* App::getInstance() {
    std::lock_guard<std::mutex> lock(instance->mtx); // Lock the mutex for thread safety
    if (!instance) {
        instance = new App();
    }
    return instance;
}

App::App() : isRunning(false) {}

App::~App() {}

void App::run() {
    isRunning = true;
    while (isRunning) {
        SDL_Event event;
        handleEvents(event);
        update();
        render();
    }
}

void App::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow("My SDL App", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        return;
    }
}
void App::handleEvents(SDL_Event& event) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
     
}

void App::update() {}

void App::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    // Render game objects here
    SDL_RenderPresent(renderer);
}