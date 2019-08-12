#include "game_manager.hpp"

#include "utils_vector.hpp"

#define COUNT_DUNGEON 20

#define COUNT_FEATURE_BOTTOMLESS_PIT 2
#define COUNT_FEATURE_SUPER_BAT 2

constexpr int links[] = {
        1, 4, 7,
        0, 2, 9,
        1, 3, 11,
        2, 4, 13,
        0, 3, 5,
        4, 6, 14,
        5, 7, 16,
        0, 6, 8,
        7, 9, 17,
        1, 8, 10,
        9, 11, 18,
        2, 10, 12,
        11, 13, 19,
        3, 12, 14,
        5, 13, 15,
        14, 16, 19,
        6, 15, 17,
        8, 16, 18,
        10, 17, 19,
        12, 15, 18
};

GameManager::GameManager()
{
    make_dungeons();
    join_dungeons();
}

Dungeon &GameManager::get_random_dungeon()
{
    return utils::get_random(dungeons);
}

void GameManager::make_dungeons()
{
    std::vector<int> free;

    for (int i = 0; i < COUNT_DUNGEON; ++i)
        free.push_back(i);

    for (int i = 0; i < COUNT_DUNGEON; ++i)
        dungeons.emplace_back(i);

    for (int i = 0; i < COUNT_FEATURE_BOTTOMLESS_PIT; ++i)
    {
        Dungeon &dungeon = get_random_dungeon();
        while (dungeon.kind != DungeonKind::Normal) dungeon = get_random_dungeon();
        dungeon.kind = DungeonKind::BottomlessPit;
    }

    for (int i = 0; i < COUNT_FEATURE_SUPER_BAT; ++i)
    {
        Dungeon &dungeon = get_random_dungeon();
        while (dungeon.kind != DungeonKind::Normal) dungeon = get_random_dungeon();
        dungeon.kind = DungeonKind::SuperBat;
    }
}

void GameManager::join_dungeons()
{

}


