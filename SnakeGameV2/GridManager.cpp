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

GridManager::GridObject GridManager::GetIsSquareOccupied(const Point2D pos)
{
    return m_grid[CalculateElementIndex(pos.x, pos.y)];
}

Point2D GridManager::GetSquareCoordinates(const int16_t x, const int16_t y)
{
    float xPos = x * (DISPLAY_WIDTH / m_gridSize);
    float yPos = y * (DISPLAY_HEIGHT / m_gridSize);

    return Point2D(xPos, yPos);
}

bool GridManager::IsPosOutsideOfGrid(Point2D pos)
{
    if (pos.x < 0 || pos.x >= m_gridSize || pos.y < 0 || pos.y >= m_gridSize)
    {
        return true;
    }

    return false;
}
