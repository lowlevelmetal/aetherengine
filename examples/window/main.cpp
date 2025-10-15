/**
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Basic Window Example
 * main.cpp
 */

#include "Aether/Engine.hpp"

#include <iostream>
#include <stdexcept>

int main() {
    auto engine = Aether::Engine::CreateEngine("Basic Window", 1280, 720);

    try {
        engine->init();
        bool quit = false;

        while (!quit) {
            quit = engine->handleEvents();
            engine->clear();
            engine->draw();
            engine->present();
        }

        engine->cleanup();

    } catch (std::runtime_error &err) {
        std::cerr << err.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
