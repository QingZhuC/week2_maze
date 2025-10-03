#include "../include/GameStart.hpp"
#include "../include/control.hpp"
#include "../include/judge.hpp"

void Start_Map1(sf::RenderWindow *window,sf::Font *font)
{
    sf::Event event;
    MyCharacter mycharacter(3,0,4);
    GridMap map(15,10,50);
    
    map.setLocalMap(1);
    map.updateGridCell( mycharacter.getxNow(), mycharacter.getyNow(), GridState::CHARACTER);
    map.updateGridCell( 14, 0, GridState::END);
    map.updateGridCell( 3, 2, GridState::TRAP);
    map.updateGridCell( 6, 8, GridState::TRAP);
    map.updateGridCell( 13, 8, GridState::TRAP);
    
    window->setTitle("MAP1");

    short count = 0;
    int EndFlag = 0;
    while(window->isOpen())
    {
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window->close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                return ;
            }
        }

        window->clear();
        map.MapPrint(window);//打印地图
        if(count == 100 && EndFlag == 10)//限定刷新速度
        {
            CharacterControl(&mycharacter, &map);//人物控制
            count = 0;
        }
        
        mycharacter.ShowHP(window);//显示血量

        EndFlag = judge(&mycharacter, &map,window,font);//结束标志        
        window->display();
        count++;
    }
}

void Start_Map2(sf::RenderWindow *window,sf::Font *font)
{
    sf::Event event;
    MyCharacter mycharacter(3,0,6);
    GridMap map(15,10,50);
    
    map.setLocalMap(2);
    map.updateGridCell( mycharacter.getxNow(), mycharacter.getyNow(), GridState::CHARACTER);
    map.updateGridCell( 4, 0, GridState::END);
    map.updateGridCell( 7, 5, GridState::TRAP);
    map.updateGridCell( 3, 2, GridState::TRAP);
    map.updateGridCell( 14, 8, GridState::TRAP);
    
    window->setTitle("MAP2");
    
    short count = 0;
    int EndFlag = 0;
    while(window->isOpen())
    {
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window->close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                return ;
            }
        }

        window->clear();
        map.MapPrint(window);//打印地图
        if(count == 100 && EndFlag == 10)//限定刷新速度
        {
            CharacterControl(&mycharacter, &map);//人物控制
            count = 0;
        }
        
        mycharacter.ShowHP(window);//显示血量

        EndFlag = judge(&mycharacter, &map,window,font);//结束标志        
        window->display();
        count++;
    }
}