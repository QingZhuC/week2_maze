#include "../include/judge.hpp"

int judge(MyCharacter *mycharacter,GridMap *map)
{
    if(mycharacter->getHP() <= 0)
        return  0;
    for(int y = 0;y < map->getHeight();y++)
    {
        for(int x = 0;x < map->getWidth();x++)
        {
            if(map->getGridState(x, y) == GridState::END)
            return 10;
        }
    }
    return 1;

}