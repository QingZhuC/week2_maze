#ifndef WEEK2_MAZE_INCLUDE_CHARACTER_HPP
#define WEEK2_MAZE_INCLUDE_CHARACTER_HPP

class MyCharacter
{
private:
    int _HP;
    int _xNow,_yNow;
public:
    MyCharacter(int HPSet,int xNowSet,int yNowSet);
    int getHP();
    int getxNow();
    int getyNow();
    void setHP(int HPSet);
    void setxNow(int xSet);
    void setyNow(int ySet);
};

#endif