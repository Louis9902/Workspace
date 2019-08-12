cmake_minimum_required(VERSION 3.15)
project(WumpusGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(WumpusGame main.cpp game_manager.cpp game_manager.hpp dungeon.cpp dungeon.hpp utils_vector.hpp utils_vector.cpp utils_random.cpp utils_random.hpp)