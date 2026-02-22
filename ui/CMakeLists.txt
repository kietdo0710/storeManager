# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.27)

# Define the project name and the languages used
project(ui LANGUAGES CXX)

find_package(clock REQUIRED)

add_library(ui SHARED ui.cpp)
target_link_libraries(ui LINK_PRIVATE clock::clock ncurses)

set_target_properties(ui PROPERTIES PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/ui.hpp;)

install(TARGETS ui)