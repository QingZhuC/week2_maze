#include "../include/character.hpp"
#include "../include/control.hpp"
#include "../include/map.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

sf::RenderWindow window(sf::VideoMode({750,500}),"MAZE",sf::Style::Close);


int main()
{
    sf::Event event;
    MyCharacter mycharacter(3,0,2);
    GridMap Map1(15,10,50);
    Map1.setLocalMap();
    window.clear(sf::Color::Black);
    
    while(window.isOpen())
    {
       while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        Map1.MapPrint();
        CharacterControl(&mycharacter, &Map1);
        window.display();
    }
}