#include "GridManager.h"
#include "MainGame.h"



int16_t GridManager::CalculateElementIndex(const int16_t x, const int16_t y)
{
    return ((y - 1) * m_gridSize) + x;
}

void GridManager::FillGridSquare(GridObject obj, const int16_t x, const int16_t y)
{
    int16_t index = CalculateElementIndex(x, y);
    m_grid[index] = obj;
}

void GridManager::EmptyGridSquare(const int16_t x, const int16_t y)
{
    int16_t index = CalculateElementIndex(x, y);
    m_grid[index] = GridObject::kNone;
}

int16_t GridManager::GetGridSize()
{
    return m_gridSize;
}

GridManager::GridObject GridManager::GetIsSquareOccupied(const int16_t index)
{
    return m_grid[index];
}

GridManager::GridObject GridManager::GetIsSquareOccupied(const int16_t x, const int16_t y)
{
    return m_grid[CalculateElementIndex(x, y)];
}

Point2D GridManager::GetSquareCoordinates(const int16_t x, const int16_t y)
{
    float xPos = x * (DISPLAY_WIDTH / m_gridSize);
    float yPos = y * (DISPLAY_HEIGHT / m_gridSize);

    return Point2D(xPos, yPos);
}
