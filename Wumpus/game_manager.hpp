#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <vector>
#include <iostream>

#include "dungeon.hpp"

constexpr int count_dungeons = 20;
constexpr int count_links_per_dungeon = 3;

constexpr int count_feature_bottomless_pit = 2;
constexpr int count_feature_super_bat = 2;

constexpr int range_arrow_min = 1;
constexpr int range_arrow_max = 5;

enum class PlayerAction : char
{
    Move, Shoot,
};

class GameManager
{
public:
    GameManager();

    Dungeon &get_random_dungeon();

    void print_dungeon_map(std::ostream &os);

    void run_game(std::ostream &os, std::istream &is);

private:
    void make_dungeons();

    void join_dungeons();

    void interaction(std::ostream &os, std::istream &is);

    static PlayerAction ask_action(std::ostream &os, std::istream &is);

    int ask_movement(std::ostream &os, std::istream &is, std::vector<int> selection);

    std::vector<int> find_dungeons_from(int current);

private:
    std::vector<Dungeon> dungeons;
    bool connections[count_dungeons][count_dungeons]{};
    int player;
    int wumpus;
    bool gameover = false;
};


#endif //GAME_MANAGER_HPP
