/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * EngineError.hpp
 */

#pragma once

#include "macro.hpp"

#include <string>
#include <stdexcept>

namespace Aether {

enum class EngineErrorCode {
    None = 0,
    SDLInitFailure,
    WindowCreationFailed,
    RendererCreationFailed,

    Unkown
};

class AETHERAPI EngineError : public std::runtime_error {
    public:
        EngineError(EngineErrorCode code,
                const std::string& message,
                const std::string& subsystem = "Core");

        EngineErrorCode code() const noexcept;
        const std::string& subsystem() const noexcept;

        static EngineError FromSDL(EngineErrorCode code,
                                    const std::string& subsystem = "SDL");

    private:
        EngineErrorCode code_;
        std::string subsystem_;

        static std::string BuildMessage(EngineErrorCode code,
                                        const std::string& msg,
                                        const std::string& subsystem);

        static const char* ToString(EngineErrorCode code);
};

} // namespace Aether
