# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.27)

# Define the project name and the languages used
project(app LANGUAGES CXX)

find_package(clock)
find_package(ui)

add_executable(app app.cpp)

target_link_libraries(app PRIVATE clock::clock ui::ui ncurses)

install(TARGETS app)