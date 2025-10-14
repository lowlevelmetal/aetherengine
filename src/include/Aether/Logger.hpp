/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * Logger.hpp
 */

#pragma once

#include <sstream>
#include <iostream>

namespace Aether {

class Logger {
    public:
        template <typename... Args>
        static void Print(Args&&... args) {
            std::ostringstream oss;
            ((oss << std::forward<Args>(args)), ...);
            std::cout << "AETHER LOG: " << oss.str() << std::endl;
        }
        
        template <typename... Args>
        static void Debug(Args&&... args) {
#ifdef _DEBUG
            std::ostringstream oss;
            ((oss << std::forward<Args>(args)), ...);
            std::cout << "AETHER DEBUG: " << oss.str() << std::endl;
#endif
        }

        template <typename... Args>
        static void Warn(Args&&... args) {
            std::ostringstream oss;
            ((oss << std::forward<Args>(args)), ...);
            std::cout << "AETHER WARN: " << oss.str() << std::endl;
        }

        template <typename... Args>
        static void Error(Args&&... args) {
            std::ostringstream oss;
            ((oss << std::forward<Args>(args)), ...);
            std::cerr << "AETHER ERROR: " << oss.str() << std::endl; 
        }
};

} // namespace Aether
