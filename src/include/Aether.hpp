/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Aether.hpp
 */

#pragma once

#ifdef AETHER_ENGINE_INTERNAL
#include "SDL3/SDL.h"
#endif

#include "macro.hpp"

#include <string>
#include <stdexcept>
#include <sstream>

namespace Aether {

class AETHERAPI Engine {
    public:
        Engine(std::string windowTitle, uint16_t resx, uint16_t resy);
        ~Engine();

        void init();
        void cleanup();
        bool handleEvents();
        void clear();
        void present();

    private:
        std::string windowTitle_;
        uint16_t resx_;
        uint16_t resy_;
#ifdef AETHER_ENGINE_INTERNAL
        SDL_Window* win_ = nullptr;
        SDL_Renderer* renderer_ = nullptr;
#endif
        bool cleaned_ = false;
};

enum class EngineErrorCode {
    None = 0,
    SDLInitFailure,
    WindowCreationFailed,
    RendererCreationFailed,

    Unkown
};

class AETHERAPI EngineError : public std::runtime_error {
    public:
        EngineError(EngineErrorCode code,
                const std::string& message,
                const std::string& subsystem = "Core");

        EngineErrorCode code() const noexcept;
        const std::string& subsystem() const noexcept;

        static EngineError FromSDL(EngineErrorCode code,
                                    const std::string& subsystem = "SDL");

    private:
        EngineErrorCode code_;
        std::string subsystem_;

        static std::string BuildMessage(EngineErrorCode code,
                                        const std::string& msg,
                                        const std::string& subsystem);

        static const char* ToString(EngineErrorCode code);
};

} // namespace Aether
