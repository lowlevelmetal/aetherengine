/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Aether.cpp
 */

#include "include/Aether.hpp"

namespace Aether {

Engine::Engine(std::string windowTitle, uint16_t resx, uint16_t resy)
                :   windowTitle_(windowTitle),
                    resx_(resx), resy_(resy)
{}

Engine::~Engine() {
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


EngineError::EngineError(EngineErrorCode code,
                const std::string& message,
                const std::string& subsystem)
            : std::runtime_error(BuildMessage(code, message, subsystem)),
                code_(code),
                subsystem_(subsystem)
{}

EngineErrorCode EngineError::code() const noexcept { return code_; }
const std::string& EngineError::subsystem() const noexcept { return subsystem_; }

EngineError EngineError::FromSDL(EngineErrorCode code, const std::string& subsystem) {
    return EngineError(code, SDL_GetError(), subsystem);
}

std::string EngineError::BuildMessage(EngineErrorCode code,
                                        const std::string& msg,
                                        const std::string& subsystem)
{
    std::ostringstream ss;
    ss << "[" << subsystem << "] " << msg << " (" << ToString(code) << ")";
    return ss.str();
}

const char* EngineError::ToString(EngineErrorCode code) {
    switch(code) {
        case EngineErrorCode::None: return "None";
        case EngineErrorCode::SDLInitFailure: return "SDLInitFailure";
        case EngineErrorCode::WindowCreationFailed: return "SDLCreateWindow failure";
        case EngineErrorCode::RendererCreationFailed: return "SDLCreateRenderer failure";
        case EngineErrorCode::Unkown: return "Unkown";
    }
    return "Unkown";
}

} // namespace Aether
