# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.27)

# Define the project name and the languages used
project(mystore LANGUAGES CXX)

# Add subdirectories to the build
add_subdirectory(ui)
add_subdirectory(clock)