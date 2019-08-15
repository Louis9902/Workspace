#include "game_manager.hpp"

#include <iomanip>
#include <algorithm>

#include "utils.hpp"

using std::vector;

constexpr int links[] = {1, 4, 7, 0, 2, 9, 1, 3, 11, 2, 4, 13,
                         0, 3, 5, 4, 6, 14, 5, 7, 16, 0, 6, 8,
                         7, 9, 17, 1, 8, 10, 9, 11, 18, 2, 10, 12,
                         11, 13, 19, 3, 12, 14, 5, 13, 15, 14, 16, 19,
                         6, 15, 17, 8, 16, 18, 10, 17, 19, 12, 15, 18};

GameManager::GameManager()
{
    make_dungeons();
    join_dungeons();
    player = utils::rnd_int_range(0, count_dungeons);
    wumpus = utils::rnd_int_range(0, count_dungeons);
}

Dungeon &GameManager::get_random_dungeon()
{
    int idx = utils::rnd_int_range(0, count_dungeons);
    return dungeons.at(idx);
}

void GameManager::print_dungeon_map(std::ostream &os)
{
    constexpr int width = 3;

    os << "   ";
    for (int i = 0; i < count_dungeons; ++i)
        os << std::setw(width) << i;
    os << '\n';
    for (int i = 0; i < count_dungeons; ++i)
    {
        os << std::setw(width) << i;
        for (int j = 0; j < count_dungeons; ++j)
        {
            if (i != j)
                os << std::setw(width) << (connections[i][j] ? '1' : '0');
            else
                os << std::setw(width) << '~';
        }
        os << '\n';
    }
}

void GameManager::run_game(std::ostream &os, std::istream &is)
{
    do
    {
        interaction(os, is);
        gameover = true;
    } while (!gameover);
}

void GameManager::make_dungeons()
{
    for (int i = 0; i < count_dungeons; ++i)
        dungeons.emplace_back(i);

    for (int i = 0; i < count_feature_bottomless_pit; ++i)
    {
        Dungeon &dungeon = get_random_dungeon();
        while (dungeon.kind != DungeonKind::Normal) dungeon = get_random_dungeon();
        dungeon.kind = DungeonKind::BottomlessPit;
    }

    for (int i = 0; i < count_feature_super_bat; ++i)
    {
        Dungeon &dungeon = get_random_dungeon();
        while (dungeon.kind != DungeonKind::Normal) dungeon = get_random_dungeon();
        dungeon.kind = DungeonKind::SuperBat;
    }
}

void GameManager::join_dungeons()
{
    int index = 0;
    for (auto &connection : connections)
        for (int j = 0; j < count_links_per_dungeon; ++j)
            connection[links[index++]] = true;
}

void GameManager::interaction(std::ostream &os, std::istream &is)
{
    vector<int> connect = find_dungeons_from(player);
    os << "You are in dungeon \u001b[31;1m" << player << "\u001b[0m\n";
    os << "The are the following dungeons connected to this cave: \u001b[36;1m";
    for (int &it : connect) os << it << ' ';
    os << "\u001b[0m\n";
    PlayerAction action = ask_action(os, is);
    switch (action)
    {
        case PlayerAction::Move:
        {
            int dungeon = ask_movement(os, is, connect);
            os << "You have chosen: " << dungeon;
        }
            break;
        case PlayerAction::Shoot:
        {
        }
            break;
    }
}

PlayerAction GameManager::ask_action(std::ostream &os, std::istream &is)
{
    os << "Do you want to [m]ove or [s]hoot?" << '\n' << "> ";
    for (char ch; is >> ch;)
    {
        switch (ch)
        {
            case 'm':
                return PlayerAction::Move;
            case 's':
                return PlayerAction::Shoot;
            default:
                continue;
        }
    }
}

int GameManager::ask_movement(std::ostream &os, std::istream &is, std::vector<int> selection)
{
    int result = 0;
    while (std::find(selection.begin(), selection.end(),
                     (result = utils::io::int_value(os, is, "> ", "please look at the selection"))) == selection.end());
    return result;
}

std::vector<int> GameManager::find_dungeons_from(int current)
{
    std::vector<int> result;
    for (int i = 0; i < count_dungeons; ++i)
    {
        if (connections[current][i]) result.push_back(i);
    }
    return result;
}

int get_int(std::istream &is)
{
    int result = 0;
    read:
    if (is >> result) return result;
    if (is.fail())
    {
        is.clear();
        for (char c; is >> c;)
        {
            if (isdigit(c) || c == '-')
            {
                is.unget();
                goto read;
            }
        }
    }
    throw std::runtime_error(is.bad() ? "corrupt input stream" : "end of file for input stream");
}


