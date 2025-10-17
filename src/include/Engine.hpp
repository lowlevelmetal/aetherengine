/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Engine.hpp
 */

#pragma once

#include "SDL3/SDL.h"

#include "Aether/Engine.hpp"
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
class AETHERAPI EngineImpl final : public Engine {
  public:
    EngineImpl(std::string windowTitle, uint16_t resx, uint16_t resy);
    ~EngineImpl() override;

    void init() override;
    void cleanup() override;
    bool handleEvents() override;
    void clear() override;
    void draw() override;
    void present() override;

  private:
    std::string windowTitle_;
    uint16_t resx_;
    uint16_t resy_;
    SDL_Window *win_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;
    bool cleaned_ = false;
};

} // namespace Aether
