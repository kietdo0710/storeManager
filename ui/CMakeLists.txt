# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.27)

# Define the project name and the languages used
project(ui LANGUAGES CXX)

add_library(ui ui.cpp)

set_target_properties(ui PROPERTIES PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/ui.hpp;)

install(TARGETS ui)