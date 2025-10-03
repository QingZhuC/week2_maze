#include "../include/judge.hpp"
#include "../include/UI.hpp"


int judge(MyCharacter *mycharacter,GridMap *map,sf::RenderWindow *window,sf::Font *font)
{
    
    if(mycharacter->getHP() <= 0)
    { 
        LoseShow(window, font);
        return  0;
    }
    for(int y = 0;y < map->getHeight();y++)
    {
        for(int x = 0;x < map->getWidth();x++)
        {
            if(map->getGridState(x, y) == GridState::END)
            return 10;
        }
    }
    WinShow(window, font);
    return 1;

}