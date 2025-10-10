cmake_minimum_required(VERSION 3.16)
project(AetherEngine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

set(SDL_SHARED OFF CACHE BOOL "Build SDL statically" FORCE)
set(SDL_STATIC ON CACHE BOOL "Build SDL static library" FORCE)
set(CMAKE_POSITION_INDEPENDENT_CODE ON CACHE BOOL "Build PIC code for static lib" FORCE)

add_subdirectory(3rd/sdl)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(aether SHARED ${SOURCES})

target_compile_definitions(aether PRIVATE SDL_STATIC)

target_link_libraries(aether PRIVATE SDL3::SDL3-static)
