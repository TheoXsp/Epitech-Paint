cmake_minimum_required(VERSION 3.24)
project(paint)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio system window REQUIRED)

include_directories(include)
add_executable(paint main.cpp include/frames.hpp include/core.hpp include/renderer.hpp src/frames.cpp src/renderer.cpp)
target_link_libraries(paint sfml-graphics sfml-audio sfml-system)