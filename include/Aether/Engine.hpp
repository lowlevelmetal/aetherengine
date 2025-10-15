/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * This file for client applications only
 *
 * Engine.hpp
 */

#pragma once

#include <cstdint>
#include <memory>
#include <string>

namespace Aether {

class Engine {
  public:
    static std::unique_ptr<Engine> CreateEngine(std::string windowTitle,
                                                uint16_t resx, uint16_t resy);

    void init();
    void cleanup();
    bool handleEvents();
    void clear();
    void draw();
    void present();
};

} // namespace Aether
