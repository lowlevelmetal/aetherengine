/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Aether.hpp
 */

#include "macro.hpp"

#include <string>

namespace Aether {

class AETHERAPI Engine {
    public:
        Engine(std::string windowTitle, uint16_t resx, uint16_t resy);
        ~Engine();

        bool handleEvents();
        bool clear();
        bool present();
};

} // namespace Aether
