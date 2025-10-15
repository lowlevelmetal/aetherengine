/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * EngineError.cpp
 */

#include "SDL3/SDL.h"

#include "Aether/EngineError.hpp"

#include <sstream>

namespace Aether {

EngineError::EngineError(EngineErrorCode code,
                         const std::string &message,
                         const std::string &subsystem)
    : std::runtime_error(BuildMessage(code, message, subsystem)),
      code_(code),
      subsystem_(subsystem) {}

EngineErrorCode EngineError::code() const noexcept { return code_; }
const std::string &EngineError::subsystem() const noexcept { return subsystem_; }

// Easy SDL related error
EngineError EngineError::FromSDL(EngineErrorCode code, const std::string &subsystem) {
    return EngineError(code, SDL_GetError(), subsystem);
}

std::string EngineError::BuildMessage(EngineErrorCode code,
                                      const std::string &msg,
                                      const std::string &subsystem) {
    std::ostringstream ss;
    ss << "[" << subsystem << "] " << msg << " (" << ToString(code) << ")";
    return ss.str();
}

const char *EngineError::ToString(EngineErrorCode code) {
    switch (code) {
    case EngineErrorCode::None:
        return "None";
    case EngineErrorCode::SDLInitFailure:
        return "SDLInitFailure";
    case EngineErrorCode::WindowCreationFailed:
        return "SDLCreateWindow failure";
    case EngineErrorCode::RendererCreationFailed:
        return "SDLCreateRenderer failure";
    case EngineErrorCode::WindowAndRendererCreationFailed:
        return "SDLCreateWindowAndRenderer failure";
    case EngineErrorCode::Unknown:
        return "Unkown";
    }
    return "Unkown";
}

} // namespace Aether
