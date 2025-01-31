cmake_minimum_required(VERSION 3.22.0)
project(aisnake VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(aisnake)
add_subdirectory(src)
