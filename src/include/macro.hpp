/*
 * Aether Engine
 * Matthew Todd Geiger
 *
 * macro.hpp
 */

#pragma once

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __attribute__((visibility("default")))
#endif

#ifdef AETHER_ENGINE_INTERNAL
#define AETHERAPI DLL_EXPORT
#else
#define AETHERAPI
#endif
