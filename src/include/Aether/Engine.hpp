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
#include <cstdint>
#include <memory>

namespace Aether {

/*
 * Engine
 *
 * Main engine implementation
 */
class AETHERAPI Engine {
    private:
        Engine(std::string windowTitle, uint16_t resx, uint16_t resy);

    public:
        ~Engine();

        static std::unique_ptr<Engine> CreateEngine(std::string windowTitle, uint16_t resx, uint16_t resy);

        void init();
        void cleanup();
        bool handleEvents();
        void clear();
        void draw();
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
