#include "../include/map.hpp"
#include "../include/LocalMap.hpp"

#include <cstdlib>
#include <ctime>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


extern sf::RenderWindow window;


GridCell::GridCell()
{
    _state = GridState::UNKNOWN;
    _x = _y = 0.0;
}

void GridCell::SetCoordinates(double xSet,double ySet)
{
    _x = xSet;
    _y = ySet;
}

void GridCell::SetState(GridState NewState)
{
    _state = NewState;
}

void GridCell::getXY(double *xGet,double *yGet)
{
    *xGet = _x;
    *yGet = _y;
}

GridState GridCell::getState()
{
    return  _state;
}

GridMap::GridMap(int widthSet,int heightSet,float resolutionSet)
{
    _width = widthSet;
    _height = heightSet;
    _resolution = resolutionSet;
    
    _grid.resize(_height,std::vector<GridCell>(_width));

    for(int y = 0; y < _height; y++)
    {
        for(int x = 0; x < _width; x++)
        {
            _grid[y][x].SetCoordinates(x*_resolution, y*_resolution);
            _grid[y][x].SetState(GridState::UNKNOWN);
        }
    }
}

void GridMap::updateGridCell(int xIndex,int yIndex,GridState NewState)
{
    if(xIndex >= 0 && xIndex < _width && yIndex >= 0 && yIndex < _height)
    {
        _grid[yIndex][xIndex].SetState(NewState);
    }
    else
    {
        return;
    }
}

GridState GridMap::getGridState(int xIndex,int yIndex)
{
    if(xIndex >= 0 && xIndex < _width && yIndex >= 0 && yIndex < _height)
    {
        return _grid[yIndex][xIndex].getState();
    }
    else
    {
        return GridState::UNKNOWN;
    }
}

void GridMap::MapPrint()
{
    sf::CircleShape circle(25.f,30);
    sf::RectangleShape rectangle({_resolution,_resolution});
    for(int y = 0; y < _height; y++)
    {
        for(int x = 0; x < _width; x++)
        {
            rectangle.setPosition({x*_resolution,y*_resolution});
            rectangle.setOutlineThickness(-1);
            circle.setPosition({x*_resolution,y*_resolution});
            switch (_grid[y][x].getState())
            {

            case GridState::FREE:
                rectangle.setFillColor(sf::Color::White);
                rectangle.setOutlineColor(sf::Color::Black);
                window.draw(rectangle);
                break;
            case GridState::OCCUPIED:
                rectangle.setFillColor(sf::Color::Black);
                rectangle.setOutlineColor(sf::Color::White);
                window.draw(rectangle);
                break;
            case GridState::UNKNOWN:
                rectangle.setFillColor({128,128,128});
                rectangle.setOutlineColor({128,128,128});
                window.draw(rectangle);
                break;
            case GridState::CHARACTER:
                circle.setFillColor(sf::Color::Blue);
                circle.setPointCount(30);
                window.draw(circle);
                break;
            case GridState::TRAP:
                circle.setFillColor(sf::Color::Magenta);
                circle.setPointCount(3);
                rectangle.setFillColor(sf::Color::White);
                rectangle.setOutlineColor(sf::Color::Black);
                window.draw(rectangle);
                window.draw(circle);
                break;
            case GridState::END:
                circle.setFillColor(sf::Color::Green);
                circle.setPointCount(4);
                rectangle.setFillColor(sf::Color::White);
                rectangle.setOutlineColor(sf::Color::Black);
                window.draw(rectangle);
                window.draw(circle);
                break;
            }
        }
    }

}

void GridMap::setLocalMap()
{
    short i = 0;
    for(int y = 0; y < _height; y++)
    {
        for (int x = 0; x < _width; x++)
        {
            i = (map1[y] >> (_width-x)) & 0x01;
            switch(i)
            {
            case 1:
                _grid[y][x].SetState(GridState::OCCUPIED);
                break;
            case 0:
                _grid[y][x].SetState(GridState::FREE);
                break;
            }
        }
    }
}

int GridMap::getWidth()
{
    return  _width;
}
int GridMap::getHeight()
{
    return _height;
}

MapTrap::MapTrap()
{
    SetState(GridState::TRAP);
}

void MapTrap::SetTrapCoordinates(double xSet,double ySet)
{
    SetCoordinates(xSet, ySet);
}

int MapTrap::GenerateTrap(GridMap *map)
{
    double xTrap,yTrap;
    int width = map->getWidth();
    int height = map->getHeight();

    getXY(&xTrap, &yTrap);
    if(map->getGridState(xTrap, yTrap) == GridState::TRAP)
    {
        map->updateGridCell(xTrap, yTrap, GridState::FREE);
    }

    srand(time(NULL));
    //do {
    //{
        xTrap = rand() % width;
        yTrap = rand() % height;
    //}
    //}while (map->getGridState(xTrap, yTrap) != GridState::FREE);
    if(map->getGridState(xTrap, yTrap) == GridState::FREE)
    {
        map->updateGridCell(xTrap,yTrap,GridState::TRAP);
        SetTrapCoordinates(xTrap, yTrap);
        return 1;
    }
    return 0;
}