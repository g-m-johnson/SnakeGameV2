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

    const int16_t CalculateElementIndex(const int16_t x, const int16_t y) const;
    const int16_t CalculateElementIndex(Point2D pos) const;

    void FillGridSquare(GridObject obj, const int16_t x, const int16_t y);
    
    void EmptyGridSquare(const int16_t x, const int16_t y);

    const int16_t GetGridSize() const;
    
    const GridObject GetIsSquareOccupied(const int16_t index) const;
    const GridObject GetIsSquareOccupied(const int16_t x, const int16_t y) const;
    const GridObject GetIsSquareOccupied(const Point2D pos) const;

    Point2D GetSquareCoordinates(const int16_t x, const int16_t y);

    bool IsPosOutsideOfGrid(Point2D pos);

    const Point2D GetRandomEmptyGridSquare() const;

private:

    GridManager() {}

    const static int m_gridSize = 16;

    GridObject m_grid[m_gridSize * m_gridSize] = {GridObject::kNone};
};

