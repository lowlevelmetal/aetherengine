# --- examples/CMakeLists.txt ---

# Collect all example directories automatically
file(GLOB EXAMPLE_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")

foreach(EXAMPLE ${EXAMPLE_DIRS})
    if (IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE}")
        add_subdirectory(${EXAMPLE})
    endif()
endforeach()

