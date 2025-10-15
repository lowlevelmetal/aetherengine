/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Engine.hpp
 */

#pragma once

#include "SDL3/SDL.h"

#include "macro.hpp"

#include <cstdint>
#include <memory>
#include <string>

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
    SDL_Window *win_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;
    bool cleaned_ = false;
};

} // namespace Aether
