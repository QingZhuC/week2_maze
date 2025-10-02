#include "../include/character.hpp"

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