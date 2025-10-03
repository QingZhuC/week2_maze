#include "../include/UI.hpp"

int main()
{
    //初始化字体库
    sf::Font font;
    while(!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"));
    //创建窗口对象
    sf::RenderWindow window;
    //运行主菜单
    MainMenu(&window,&font);
}