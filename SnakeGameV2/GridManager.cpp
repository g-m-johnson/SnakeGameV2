#include "GridManager.h"

int16_t GridManager::CalculateElementIndex(const int16_t x, const int16_t y)
{
    return ((y - 1) * m_gridSize) + x;
}

void GridManager::FillGridSquare(const int16_t x, const int16_t y)
{
    int16_t index = CalculateElementIndex(x, y);
    m_grid[index] = true;
}

void GridManager::EmptyGridSquare(const int16_t x, const int16_t y)
{
    int16_t index = CalculateElementIndex(x, y);
    m_grid[index] = false;
}

int16_t GridManager::GetGridSize()
{
    return m_gridSize;
}

bool GridManager::GetIsSquareOccupied(const int16_t index)
{
    return m_grid[index];
}

bool GridManager::GetIsSquareOccupied(const int16_t x, const int16_t y)
{
    return m_grid[CalculateElementIndex(x, y)];
}
