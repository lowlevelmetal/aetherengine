/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Logger.hpp
 */

#pragma once

#include <iostream>
#include <sstream>

#ifdef _DEBUG
#define DEBUG(...) Aether::Logger::Debug(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

#define PRINT(...) Aether::Logger::Print(__VA_ARGS__)
#define WARN(...) Aether::Logger::Warn(__VA_ARGS__)
#define ERROR(...) Aether::Logger::Error(__VA_ARGS__)

namespace Aether {

class Logger {
  public:
    template <typename... Args>
    static void Print(Args &&...args) {
        std::ostringstream oss;
        ((oss << std::forward<Args>(args)), ...);
        std::cout << "AETHER LOG: " << oss.str() << std::endl;
    }

    template <typename... Args>
    static void Debug(Args &&...args) {
        std::ostringstream oss;
        ((oss << std::forward<Args>(args)), ...);
        std::cout << "AETHER DEBUG: " << oss.str() << std::endl;
    }

    template <typename... Args>
    static void Warn(Args &&...args) {
        std::ostringstream oss;
        ((oss << std::forward<Args>(args)), ...);
        std::cout << "AETHER WARN: " << oss.str() << std::endl;
    }

    template <typename... Args>
    static void Error(Args &&...args) {
        std::ostringstream oss;
        ((oss << std::forward<Args>(args)), ...);
        std::cerr << "AETHER ERROR: " << oss.str() << std::endl;
    }
};

} // namespace Aether
