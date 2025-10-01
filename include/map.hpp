#ifndef WEEK2_MAZE_INCLUDE_MAP_HPP
#define WEEK2_MAZE_INCLUDE_MAP_HPP

#include <vector>
enum struct GridState
{
    FREE,
    OCCUPIED,
    UNKNOWN
};

class GridCell
{
private:
    GridState _state;
    double _x,_y;
public:
    GridCell();
    void SetCoordinates(double,double);
};

class GridMap
{
private:
    std::vector<std::vector<GridCell>> _grid;
    int _width;
    int _height;
public:
    void MapPrint();
};

#endif