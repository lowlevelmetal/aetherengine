/**
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Basic Window Example
 * main.cpp
 */

#include "Aether.hpp"
#include <iostream>

int main() {
    Aether::Engine engine("Basic Window", 640, 480);
    
    try {
        engine.init();
        bool quit = false;

        while(!quit) {
            quit = engine.handleEvents();
        }

        engine.cleanup();

    } catch(Aether::EngineError& err) {
        std::cerr << err.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
