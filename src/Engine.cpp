/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Engine.cpp
 */

#include "Engine.hpp"
#include "Aether/Engine.hpp"
#include "EngineError.hpp"
#include "Logger.hpp"

#include <memory>

namespace Aether {

EngineImpl::EngineImpl(std::string windowTitle, uint16_t resx, uint16_t resy)
    : windowTitle_(windowTitle), resx_(resx), resy_(resy) {
    DEBUG("Constructing Aether Engine");
}

EngineImpl::~EngineImpl() {
    DEBUG("Deconstructing Engine");

    // Cleaning up is supposed to happen manually(to properly catch errors), but
    // I'll do it if you didn't
    if (!cleaned_) {
        DEBUG("Engine auto clean running");
        cleanup();
    }
}

Engine::~Engine() = default;

std::unique_ptr<Engine> Engine::CreateEngine(std::string windowTitle,
                                             uint16_t resx, uint16_t resy) {
    DEBUG("Engine factory spinning up new engine");
    return std::unique_ptr<Engine>(new EngineImpl(std::move(windowTitle), resx, resy));
}

void EngineImpl::init() {
    DEBUG("Initializing SDL: ", SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        ERROR("Failed to initialize SDL");
        throw EngineError::FromSDL(EngineErrorCode::SDLInitFailure);
    }

    DEBUG("Creating SDL window and renderer (", resx_, ",", resy_, ")");
    if (!SDL_CreateWindowAndRenderer(windowTitle_.c_str(), resx_, resy_,
                                     SDL_WINDOW_RESIZABLE, &win_, &renderer_)) {
        ERROR("Failed to create SDL window and renderer");
        throw EngineError::FromSDL(
            EngineErrorCode::WindowAndRendererCreationFailed);
    }

    DEBUG("Defining SDL renderer logical presentation (", resx_, ",",
          resy_, ")");
    SDL_SetRenderLogicalPresentation(renderer_, resx_, resy_,
                                     SDL_LOGICAL_PRESENTATION_LETTERBOX);
}

void EngineImpl::cleanup() {
    if (renderer_) {
        DEBUG("Destroying renderer");
        SDL_DestroyRenderer(renderer_);
    }

    if (win_) {
        DEBUG("Destroying window");
        SDL_DestroyWindow(win_);
    }

    if (SDL_WasInit(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        DEBUG("Quitting SDL");
        SDL_Quit();
    }

    renderer_ = nullptr;
    win_ = nullptr;
    cleaned_ = true;
}

bool EngineImpl::handleEvents() {
    SDL_Event event;

    // Read events from SDL, very similar to win32
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return true;
        }
    }

    return false;
}

void EngineImpl::clear() { SDL_RenderClear(renderer_); }

void EngineImpl::draw() {
    // Drawing would go here
    // Set to black
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
}

void EngineImpl::present() { SDL_RenderPresent(renderer_); }

} // namespace Aether
