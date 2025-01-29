cmake_minimum_required(VERSION 3.22.0)
project(aisnake VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

add_executable(aisnake main.cpp)

target_link_libraries(aisnake PRIVATE src_lib)
