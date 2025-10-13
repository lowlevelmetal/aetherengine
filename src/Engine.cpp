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

    if (!SDL_CreateWindowAndRenderer(windowTitle_.c_str(), resx_, resy_, SDL_WINDOW_RESIZABLE, &win_, &renderer_)) {
        throw EngineError::FromSDL(EngineErrorCode::WindowAndRendererCreationFailed);
    }
    SDL_SetRenderLogicalPresentation(renderer_, resx_, resy_, SDL_LOGICAL_PRESENTATION_LETTERBOX);
}

void Engine::cleanup() {
    if(renderer_) {
        SDL_DestroyRenderer(renderer_);
    }

    if(win_) {
        SDL_DestroyWindow(win_);
    }

    SDL_Quit();

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
