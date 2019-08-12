#ifndef DUNGEON_HPP
#define DUNGEON_HPP

enum class DungeonKind
{
    Normal, BottomlessPit, SuperBat
};

struct Dungeon
{
    Dungeon(int index_, int label_, DungeonKind kind_ = DungeonKind::Normal);

    int index;
    int label;
    DungeonKind kind;
};


#endif //DUNGEON_HPP
