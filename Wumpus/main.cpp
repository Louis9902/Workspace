#include <iostream>

#include "game_manager.hpp"

int main() {
    GameManager manager;

    manager.run_game(std::cout, std::cin);

    return 0;
}