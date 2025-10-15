# --- AetherEngine/examples/basic_window/CMakeLists.txt ---

add_executable(aether_example_basic_window main.cpp)

target_link_libraries(aether_example_basic_window PRIVATE aether)
target_include_directories(aether_example_basic_window PRIVATE ${PROJECT_SOURCE_DIR}/src/include)

# On Windows, SDL may need Win32 subsystem
#if (WIN32)
#    target_link_options(aether_example_basic_window PRIVATE "/SUBSYSTEM:CONSOLE")
#endif()

