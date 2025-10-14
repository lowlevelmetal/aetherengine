/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Engine.cpp
 */

#include "Aether/Engine.hpp"
#include "Aether/EngineError.hpp"
#include "Aether/Logger.hpp"

#include <memory>

namespace Aether {

Engine::Engine(std::string windowTitle, uint16_t resx, uint16_t resy)
                :   windowTitle_(windowTitle),
                    resx_(resx), resy_(resy)
{
    Logger::Debug("Constructing Aether Engine");
}

Engine::~Engine() {
    Logger::Debug("Deconstructing Engine");

    // Cleaning up is supposed to happen manually(to properly catch errors), but I'll do it if you didn't
    if(!cleaned_) {
        Logger::Debug("Engine auto clean running");
        cleanup();
    }
}

std::unique_ptr<Engine> Engine::CreateEngine(std::string windowTitle, uint16_t resx, uint16_t resy) {
    std::unique_ptr<Engine> engine(new Engine(windowTitle, resx, resy)); 
    return std::move(engine);
}

void Engine::init() {
    Logger::Debug("Initializing SDL: ", SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        Logger::Error("Failed to initialize SDL");
        throw EngineError::FromSDL(EngineErrorCode::SDLInitFailure);
    }

    Logger::Debug("Creating SDL window and renderer (", resx_, ",", resy_, ")");
    if (!SDL_CreateWindowAndRenderer(windowTitle_.c_str(), resx_, resy_, SDL_WINDOW_RESIZABLE, &win_, &renderer_)) {
        Logger::Error("Failed to create SDL window and renderer");
        throw EngineError::FromSDL(EngineErrorCode::WindowAndRendererCreationFailed);
    }

    Logger::Debug("Defining SDL renderer logical presentation (", resx_, ",", resy_, ")");
    SDL_SetRenderLogicalPresentation(renderer_, resx_, resy_, SDL_LOGICAL_PRESENTATION_LETTERBOX);
}

void Engine::cleanup() {
    if(renderer_) {
        Logger::Debug("Destroying renderer");
        SDL_DestroyRenderer(renderer_);
    }

    if(win_) {
        Logger::Debug("Destroying window");
        SDL_DestroyWindow(win_);
    }

    if(SDL_WasInit(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        Logger::Debug("Quitting SDL");
        SDL_Quit();
    }

    renderer_ = nullptr;
    win_ = nullptr;
    cleaned_ = true;
}

bool Engine::handleEvents() {
    SDL_Event event;

    // Read events from SDL, very similar to win32
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_EVENT_QUIT) {
            return true;
        }
    }

    return false;
}

void Engine::clear() {
    SDL_RenderClear(renderer_);
}

void Engine::draw() {
    // Drawing would go here
    // Set to black
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
}

void Engine::present() {
    SDL_RenderPresent(renderer_);
}

} // namespace Aether
