#include "../include/character.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

MyCharacter::MyCharacter(int HPSet,int xNowSet,int yNowSet)
{
    _HP = 3;
    _xNow = xNowSet;
    _yNow = yNowSet;
}

int MyCharacter::getHP()
{
    return _HP;
}

int MyCharacter::getxNow()
{
    return _xNow;
}

int MyCharacter::getyNow()
{
    return _yNow;
}

 void MyCharacter::setHP(int HPSet)
 {
    _HP = HPSet;
 }

void MyCharacter::setxNow(int xSet)
{
    _xNow = xSet;
}

void MyCharacter::setyNow(int ySet)
{
    _yNow = ySet;
}

void MyCharacter::ShowHP(sf::RenderWindow *window)
{
    sf::CircleShape Heart(20.f,30);
    Heart.setFillColor(sf::Color::Red);
    for(short i = 0;i < getHP();i++)
    {
        Heart.setPosition(i*50,520);
        window->draw(Heart);
    }
}