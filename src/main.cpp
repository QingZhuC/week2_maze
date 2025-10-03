#include "../include/character.hpp"
#include "../include/control.hpp"
#include "../include/map.hpp"
#include "../include/judge.hpp"

#include <SFML/Graphics.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>


sf::RenderWindow window(sf::VideoMode({750,570}),"MAZE",sf::Style::Close);
sf::Font font;

int main()
{

    while(!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"));
    sf::Event event;
    sf::Text text;
    text.setFont(font);
    sf::CircleShape Heart(20.f,30);
    Heart.setFillColor(sf::Color::Red);
    MyCharacter mycharacter(3,0,2);
    GridMap Map1(15,10,50);
    Map1.setLocalMap();
    Map1.updateGridCell( 12, 0, GridState::END);
    MapTrap trap;
    window.clear(sf::Color::Black);
    short count = 0;
    short WinFlag = 0;
    short TrapFlag = 0;
    while(window.isOpen())
    {
       while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        Map1.MapPrint();
        for(short i = 0;i<mycharacter.getHP();i++)
        {
            Heart.setPosition(i * 50,520);
            window.draw(Heart);
        }
        if(count == 100 && !WinFlag)
        {
            if(CharacterControl(&mycharacter, &Map1))
            {
                WinFlag = 1;
            }
            count = 0;
        }
        if(!TrapFlag)
        {
            if(trap.GenerateTrap(&Map1))
            {   
                TrapFlag = 10000;
            }
        }
        if(TrapFlag)
            TrapFlag--;

        if(judge(&mycharacter, &Map1) == 1)
        {
            text.setCharacterSize(72);
            text.setFillColor(sf::Color::Green);
            text.setString("YOU WIN!");
            text.setPosition(220,200);
            window.draw(text);
        }
        window.display();
        count++;
    }
}