#pragma once

#include <cstdint>
#include <array>

class GridManager
{
public:

    static GridManager& Instance()
    {
        static GridManager* pInstance = new GridManager();
        return *pInstance;
    }

    int16_t CalculateElementIndex(const int16_t x, const int16_t y);

    void FillGridSquare(const int16_t x, const int16_t y);
    
    void EmptyGridSquare(const int16_t x, const int16_t y);

    int16_t GetGridSize();
    
    bool GetIsSquareOccupied(const int16_t index);
    bool GetIsSquareOccupied(const int16_t x, const int16_t y);

private:

    GridManager() {}

    const static int m_gridSize = 16;

    bool m_grid[m_gridSize * m_gridSize] = {false};
};

