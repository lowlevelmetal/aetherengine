/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Engine.hpp
 */

#pragma once

#ifdef AETHER_ENGINE_INTERNAL
#include "SDL3/SDL.h"
#endif

#include "macro.hpp"

#include <string>

namespace Aether {

/*
 * Engine
 *
 * Main engine implementation
 */
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

} // namespace Aether
