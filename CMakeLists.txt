cmake_minimum_required(VERSION 3.16)
project(AetherEngine CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

set(SDL_SHARED OFF CACHE BOOL "Build SDL statically" FORCE)
set(SDL_STATIC ON CACHE BOOL "Build SDL static library" FORCE)
set(CMAKE_POSITION_INDEPENDENT_CODE ON CACHE BOOL "Build PIC code for static lib" FORCE)

add_subdirectory(3rd/sdl)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(aether SHARED ${SOURCES})

set_target_properties(aether PROPERTIES
    CXX_VISIBILITY_PRESET "hidden"
    VISBILITY_INLINES_HIDDEN "TRUE"
)

target_compile_definitions(aether PRIVATE SDL_STATIC AETHER_ENGINE_INTERNAL)

target_link_libraries(aether PRIVATE SDL3::SDL3-static)

option(AETHER_BUILD_EXAMPLES "Build example programs for AetherEngine" ON)

if(AETHER_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
