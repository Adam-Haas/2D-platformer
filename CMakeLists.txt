cmake_minimum_required(VERSION 3.9)

project(2D-Platformer VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

file(COPY ${PROJECT_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR}/src)