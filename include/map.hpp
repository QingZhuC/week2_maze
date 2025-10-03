#ifndef WEEK2_MAZE_INCLUDE_MAP_HPP
#define WEEK2_MAZE_INCLUDE_MAP_HPP

#include <vector>



enum struct GridState
{
    FREE,
    OCCUPIED,
    UNKNOWN,
    CHARACTER,
    TRAP,
    END
};

class GridCell//栅格单元类，存储每个栅格的信息
{
private:
    GridState _state;
    double _x,_y;
public:
    GridCell();
    void SetCoordinates(double xSet,double ySet);//设定坐标
    void SetState(GridState NewState);
    void getXY(double *xGet,double *yGet);
    GridState getState();
};

class GridMap//栅格地图类
{
private:
    std::vector<std::vector<GridCell>> _grid;//二维数组存储
    int _width;
    int _height;
    float _resolution;
public:
    GridMap(int widthSet,int heightSet,float resolutionSet);//初始化长宽
    void updateGridCell(int xIndex,int yIndex,GridState NewState);
    GridState getGridState(int xIndex,int yIndex);
    void MapPrint();
    void setLocalMap();
    int getWidth();
    int getHeight();

};

class MapTrap:public GridCell
{
public:
    MapTrap();
    void SetTrapCoordinates(double xSet,double ySet);
    int GenerateTrap(GridMap *map);
};

#endif