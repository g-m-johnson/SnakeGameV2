#pragma once

#include <cstdint>
#include <vector>
#include "Play.h"

class GridManager
{
public:

    enum class GridObject
    {
        kNone,
        kSnake, 
        kFruit,
    };

    static GridManager& Instance()
    {
        static GridManager* pInstance = new GridManager();
        return *pInstance;
    }

    int16_t CalculateElementIndex(const int16_t x, const int16_t y);

    void FillGridSquare(GridObject obj, const int16_t x, const int16_t y);
    
    void EmptyGridSquare(const int16_t x, const int16_t y);

    int16_t GetGridSize();
    
    GridObject GetIsSquareOccupied(const int16_t index);
    GridObject GetIsSquareOccupied(const int16_t x, const int16_t y);
    GridObject GetIsSquareOccupied(const Point2D pos);

    Point2D GetSquareCoordinates(const int16_t x, const int16_t y);

    bool IsPosOutsideOfGrid(Point2D pos);

private:

    GridManager() {}

    const static int m_gridSize = 16;

    GridObject m_grid[m_gridSize * m_gridSize] = {GridObject::kNone};
};

