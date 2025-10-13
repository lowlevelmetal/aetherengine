/**
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Basic Window Example
 * main.cpp
 */

#include "Aether/Engine.hpp"
#include "Aether/EngineError.hpp"

#include <iostream>

int main() {
    Aether::Engine engine("Basic Window", 1280, 720);
    
    try {
        engine.init();
        bool quit = false;

        while(!quit) {
            quit = engine.handleEvents();
            engine.clear();
            engine.draw();
            engine.present();
        }

        engine.cleanup();

    } catch(Aether::EngineError& err) {
        std::cerr << err.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
