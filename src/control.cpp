#include "../include/control.hpp"
#include <SFML/Graphics.hpp>

int CharacterControl(MyCharacter *mycharacter,GridMap *map)
{
    int mycharacter_x = mycharacter->getxNow();
    int mycharacter_y = mycharacter->getyNow();
    int map_W = map->getWidth();
    int map_H = map->getHeight();
    int ifWin = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            if(mycharacter_x-1 < map_W && mycharacter_x >= 0)
            {
                switch (map->getGridState(mycharacter_x - 1, mycharacter_y))
                {
                case GridState::END:
                    mycharacter->setHP(mycharacter->getHP()+1);
                    ifWin = 1;
                case GridState::TRAP:
                    mycharacter->setHP(mycharacter->getHP()-1);
                case GridState::FREE:
                    mycharacter->setxNow(mycharacter_x-1);
                    break;
                case GridState::OCCUPIED:
                    break;
                }
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            if(mycharacter_x+1 < map_W && mycharacter_x >= 0)
            {
                switch (map->getGridState(mycharacter_x + 1, mycharacter_y))
                {
                case GridState::END:
                    mycharacter->setHP(mycharacter->getHP()+1);
                    ifWin = 1;
                case GridState::TRAP:
                    mycharacter->setHP(mycharacter->getHP()-1);
                case GridState::FREE:
                    mycharacter->setxNow(mycharacter_x+1);
                    break;
                case GridState::OCCUPIED:
                    break;
                }
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            if(mycharacter_y+1 < map_H && mycharacter_y >= 0)
            {
                switch (map->getGridState(mycharacter_x, mycharacter_y + 1))
                {
                case GridState::END:
                    mycharacter->setHP(mycharacter->getHP()+1);
                    ifWin = 1;
                case GridState::TRAP:
                    mycharacter->setHP(mycharacter->getHP()-1);
                case GridState::FREE:
                    mycharacter->setyNow(mycharacter_y + 1);
                    break;
                case GridState::OCCUPIED:
                    break;
                }
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            if(mycharacter_y-1 < map_H && mycharacter_y >= 0)
            {
                switch (map->getGridState(mycharacter_x, mycharacter_y - 1))
                {
                case GridState::END:
                    mycharacter->setHP(mycharacter->getHP()+1);
                    ifWin = 1;
                case GridState::TRAP:
                    mycharacter->setHP(mycharacter->getHP()-1);
                case GridState::FREE:
                    mycharacter->setyNow(mycharacter_y - 1);
                    break;
                case GridState::OCCUPIED:
                    break;
                }
            }
        map->updateGridCell(mycharacter_x, mycharacter_y, GridState::FREE);
        map->updateGridCell(mycharacter->getxNow(), mycharacter->getyNow(), GridState::CHARACTER);
        return ifWin;
}

