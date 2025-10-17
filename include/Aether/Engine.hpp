/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * This file for client applications only
 *
 * Engine.hpp
 */

#pragma once

#ifdef AETHER_ENGINE_INTERNAL
#include "macro.hpp"
#else
#define AETHERAPI
#endif

#include <cstdint>
#include <memory>
#include <string>

namespace Aether {

class AETHERAPI Engine {
  public:
    virtual ~Engine();

    static std::unique_ptr<Engine> CreateEngine(std::string windowTitle,
                                                uint16_t resx, uint16_t resy);

    virtual void init() = 0;
    virtual void cleanup() = 0;
    virtual bool handleEvents() = 0;
    virtual void clear() = 0;
    virtual void draw() = 0;
    virtual void present() = 0;
};

} // namespace Aether
