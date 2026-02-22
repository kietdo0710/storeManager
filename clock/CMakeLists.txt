# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.27)

# Define the project name and the languages used
project(clock LANGUAGES CXX)

add_library(clock SHARED clock.cpp)

set_target_properties(clock PROPERTIES PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/clock.hpp;)

install(TARGETS clock)