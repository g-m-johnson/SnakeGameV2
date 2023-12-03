#include "GridManager.h"
#include "MainGame.h"



const int16_t GridManager::CalculateElementIndex(const int16_t x, const int16_t y) const
{
    return ((y - 1) * m_gridSize) + x;
}

const int16_t GridManager::CalculateElementIndex(Point2D pos) const
{
    return ((pos.y - 1) * m_gridSize) + pos.x;
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

const int16_t GridManager::GetGridSize() const
{
    return m_gridSize;
}

const GridManager::GridObject GridManager::GetIsSquareOccupied(const int16_t index) const
{
    return m_grid[index];
}

const GridManager::GridObject GridManager::GetIsSquareOccupied(const int16_t x, const int16_t y) const
{
    return m_grid[CalculateElementIndex(x, y)];
}

const GridManager::GridObject GridManager::GetIsSquareOccupied(const Point2D pos) const
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

const Point2D GridManager::GetRandomEmptyGridSquare() const
{
    bool bIsSpaceOccupied = true;
    int16_t x = 0;
    int16_t y = 0;

    while (bIsSpaceOccupied)
    {
        x = Play::RandomRoll(16);
        y = Play::RandomRoll(16);

        if (GetIsSquareOccupied(x, y) == GridObject::kNone)
        {
            bIsSpaceOccupied = false;
        }
    }

    return Point2D(x, y);
}
