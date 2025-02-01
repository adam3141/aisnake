add_subdirectory(utility)
add_subdirectory(board)
add_subdirectory(snake)

target_sources(aisnake PRIVATE main.cpp)
target_include_directories(aisnake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})