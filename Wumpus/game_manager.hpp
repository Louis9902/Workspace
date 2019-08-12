#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <vector>

#include "dungeon.hpp"

class GameManager
{
public:
    GameManager();
    Dungeon &get_random_dungeon();

private:
    void make_dungeons();
    void join_dungeons();

private:
    std::vector<Dungeon> dungeons;
    bool matrix[20][20];
};


#endif //GAME_MANAGER_HPP
