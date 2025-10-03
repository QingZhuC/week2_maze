#include "../include/UI.hpp"
#include "../include/GameStart.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

void MainMenu(RenderWindow *window,Font *font)//主菜单
{
    window->create(VideoMode({750,570}),"MainMenu",Style::Close);//初始化窗口
    //window->setFramerateLimit(60);//限定帧率
    Event event;//存储捕获事件

    RectangleShape button1({150.f,75.f});//按钮1初始化
    button1.setFillColor({128,128,128});
    button1.setOutlineColor(Color::White);
    button1.setOutlineThickness(-1);
    button1.setPosition(300,100);

    RectangleShape button2({150.f,75.f});//按钮2初始化
    button2.setFillColor({128,128,128});
    button2.setOutlineColor(Color::White);
    button2.setOutlineThickness(-1);
    button2.setPosition(300,200);

    RectangleShape button3({150.f,75.f});//按钮3初始化
    button3.setFillColor({128,128,128});
    button3.setOutlineColor(Color::White);
    button3.setOutlineThickness(-1);
    button3.setPosition(300,300);

    Text text1;//文本1初始化
    text1.setFont(*font);
    text1.setCharacterSize(30);
    text1.setFillColor(Color::White);
    text1.setPosition(335,118);
    text1.setString("Map1");

    Text text2;//文本2初始化
    text2.setFont(*font);
    text2.setCharacterSize(30);
    text2.setFillColor(Color::White);
    text2.setPosition(335,218);
    text2.setString("Map2");

    Text text3;//文本3初始化
    text3.setFont(*font);
    text3.setCharacterSize(30);
    text3.setFillColor(Color::White);
    text3.setPosition(348,318);
    text3.setString("Exit");

    while(window->isOpen())//当窗口打开时...
    {
        while(window->pollEvent(event))//捕获事件，判断窗口是否关闭与跳转哪个选项
        {
            if(event.type == Event::Closed)//捕获到关闭窗口
                window->close();
            if(button1.getGlobalBounds().contains(window->mapPixelToCoords(Mouse::getPosition(*window))))//鼠标指针停在button1上，则高亮显示
            {
                text1.setFillColor(Color::Black);
                button1.setFillColor(Color::White);
                button1.setOutlineColor({128,128,128});
                if(event.type == sf::Event::MouseButtonPressed)//鼠标点击，跳转button1对应选项
                    Start_Map1(window,font);
            }
            else //未停留，按钮恢复初始状态
            {
                text1.setFillColor(Color::White);
                button1.setFillColor({128,128,128});
                button1.setOutlineColor(Color::White);
            }
            if(button2.getGlobalBounds().contains(window->mapPixelToCoords(Mouse::getPosition(*window))))//鼠标指针停在button2上，则高亮显示
            {
                text2.setFillColor(Color::Black);
                button2.setFillColor(Color::White);
                button2.setOutlineColor({128,128,128});
                if(event.type == sf::Event::MouseButtonPressed)//鼠标点击，跳转button2对应选项
                    Start_Map2(window,font);
            }
            else //未停留，按钮恢复初始状态
            {
                text2.setFillColor(Color::White);
                button2.setFillColor({128,128,128});
                button2.setOutlineColor(Color::White);
            }
            if(button3.getGlobalBounds().contains(window->mapPixelToCoords(Mouse::getPosition(*window))))//鼠标指针停在button2上，则高亮显示
            {
                text3.setFillColor(Color::Black);
                button3.setFillColor(Color::White);
                button3.setOutlineColor({128,128,128});
                if(event.type == sf::Event::MouseButtonPressed)//鼠标点击，跳转button3对应选项
                    return;
            }
            else //未停留，按钮恢复初始状态
            {
                text3.setFillColor(Color::White);
                button3.setFillColor({128,128,128});
                button3.setOutlineColor(Color::White);
            }
            

        }
        window->clear();

        window->setTitle("MainMenu");

        window->draw(button1);
        window->draw(text1);
     
        window->draw(button2);
        window->draw(text2);

        window->draw(button3);
        window->draw(text3);

        window->display();
    }
}

void WinShow(RenderWindow *window,Font *font)//用于显示胜利信息
{
    sf::Text WinText("YOU WIN!",*font,72);
    WinText.setFillColor(sf::Color::Green);
    WinText.setPosition({220,200});

    sf::RectangleShape rectangle({390,100});
    rectangle.setFillColor({128,128,128});
    rectangle.setPosition(200,200);

    window->draw(rectangle);
    window->draw(WinText);
}
void LoseShow(RenderWindow *window,Font *font)//用于显示失败信息
{
    sf::Text LoseText("YOU LOSE!",*font,72);
    LoseText.setFillColor(sf::Color::Red);
    LoseText.setPosition({190,200});

    sf::RectangleShape rectangle({420,100});
    rectangle.setFillColor({128,128,128});
    rectangle.setPosition(170,200);

    window->draw(rectangle);
    window->draw(LoseText); 
}