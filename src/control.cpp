#include "../include/control.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

extern sf::RenderWindow window;

void CharacterControl(MyCharacter *mycharacter,GridMap *map)
{
    sf::CircleShape circle(25.f,30);
    sf::Event KeyEvent;
    while(window.pollEvent(KeyEvent))
    {
        int mycharacter_x = mycharacter->getxNow();
        int mycharacter_y = mycharacter->getyNow();
        int map_W = map->getWidth();
        int map_H = map->getHeight();
        switch(KeyEvent.key.code)
        {
        case sf::Keyboard::A:
            if(mycharacter_x-1 < map_W && mycharacter_x >= 0)
            {
                switch (map->getGridState(mycharacter_x - 1, mycharacter_y))
                {
                case GridState::END:
                case GridState::TRAP:
                case GridState::FREE:
                    circle.setFillColor(sf::Color::White);
                    circle.setPosition({float(mycharacter_x*50),float(mycharacter_y*50)});
                    window.draw(circle);

                    circle.setFillColor(sf::Color::Blue);
                    circle.setPosition({float((mycharacter_x-1)*50),float(mycharacter_y*50)});
                    window.draw(circle);

                    mycharacter->setxNow(mycharacter_x-1);
                    break;
                case GridState::OCCUPIED:
                    break;

                }
            }
            break;
        case sf::Keyboard::D:
            if(mycharacter_x+1 < map_W && mycharacter_x >= 0)
            {
                switch (map->getGridState(mycharacter_x + 1, mycharacter_y))
                {
                case GridState::END:
                case GridState::TRAP:
                case GridState::FREE:
                    circle.setFillColor(sf::Color::White);
                    circle.setPosition({float(mycharacter_x*50),float(mycharacter_y*50)});
                    window.draw(circle);

                    circle.setFillColor(sf::Color::Blue);
                    circle.setPosition({float((mycharacter_x+1)*50),float(mycharacter_y*50)});
                    window.draw(circle);

                    mycharacter->setxNow(mycharacter_x+1);
                    break;
                case GridState::OCCUPIED:
                    break;

                }
            }
            break;
        case sf::Keyboard::S:
            if(mycharacter_y+1 < map_H && mycharacter_y >= 0)
            {
                switch (map->getGridState(mycharacter_x, mycharacter_y + 1))
                {
                case GridState::END:
                case GridState::TRAP:
                case GridState::FREE:
                    circle.setFillColor(sf::Color::White);
                    circle.setPosition({float(mycharacter_x*50),float(mycharacter_y*50)});
                    window.draw(circle);

                    circle.setFillColor(sf::Color::Blue);
                    circle.setPosition({float(mycharacter_x*50),float((mycharacter_y + 1)*50)});
                    window.draw(circle);

                    mycharacter->setyNow(mycharacter_y + 1);
                    break;
                case GridState::OCCUPIED:
                    break;

                }
            }
            break;
        case sf::Keyboard::W:
            if(mycharacter_y-1 < map_H && mycharacter_y >= 0)
            {
                switch (map->getGridState(mycharacter_x, mycharacter_y - 1))
                {
                case GridState::END:
                case GridState::TRAP:
                case GridState::FREE:
                    circle.setFillColor(sf::Color::White);
                    circle.setPosition({float(mycharacter_x*50),float(mycharacter_y*50)});
                    window.draw(circle);

                    circle.setFillColor(sf::Color::Blue);
                    circle.setPosition({float(mycharacter_x*50),float((mycharacter_y - 1)*50)});
                    window.draw(circle);

                    mycharacter->setyNow(mycharacter_y - 1);
                    break;
                case GridState::OCCUPIED:
                    break;

                }
            }
          break;
        }
        map->updateGridCell(mycharacter_x, mycharacter_y, GridState::FREE);
        map->updateGridCell(mycharacter->getxNow(), mycharacter->getyNow(), GridState::CHARACTER);
    }
}

