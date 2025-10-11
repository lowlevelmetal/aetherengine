/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Engine.cpp
 */

#include "Aether/Engine.hpp"
#include "Aether/EngineError.hpp"

namespace Aether {

Engine::Engine(std::string windowTitle, uint16_t resx, uint16_t resy)
                :   windowTitle_(windowTitle),
                    resx_(resx), resy_(resy)
{}

Engine::~Engine() {
    // Cleaning up is supposed to happen manually(to properly catch errors), but I'll do it if you didn't
    if(!cleaned_)
        cleanup();
}

void Engine::init() {
    if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        throw EngineError::FromSDL(EngineErrorCode::SDLInitFailure);
    }

    win_ = SDL_CreateWindow(windowTitle_.c_str(), resx_, resy_, SDL_WINDOW_RESIZABLE);
    if(!win_) {
        throw EngineError::FromSDL(EngineErrorCode::WindowCreationFailed);
    }

    renderer_ = SDL_CreateRenderer(win_, nullptr);
    if(!renderer_) {
        throw EngineError::FromSDL(EngineErrorCode::RendererCreationFailed);
    }
}

void Engine::cleanup() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(win_);

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
}

void Engine::present() {
}

} // namespace Aether
