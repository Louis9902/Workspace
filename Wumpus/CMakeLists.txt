cmake_minimum_required(VERSION 3.15)
project(WumpusGame)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-pedantic)

add_executable(WumpusGame main.cpp utils.cpp dungeon.cpp game_manager.cpp)