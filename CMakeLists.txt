cmake_minimum_required(VERSION 3.16)
project(MantisFlow
    VERSION 0.1.0
    DESCRIPTION "A computational fluid dynamics (CFD) solver"
    LANGUAGES CXX
)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Library
add_library(mantisflow ${SOURCES})

# Executable
add_executable(mantis src/main.cpp)
target_link_libraries(mantis mantisflow)

# Tests (optional)
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Install
install(TARGETS mantis DESTINATION bin)
install(TARGETS mantisflow DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
