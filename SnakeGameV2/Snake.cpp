#include "Snake.h"
#include "GridManager.h"

Snake::Snake()
{
	int16_t size = GridManager::Instance().GetGridSize();
	m_maxSnakeSize = size * size;
	m_bodyPositions.reserve(m_maxSnakeSize);
}

void Snake::InitialiseSnake()
{
}

void Snake::Update()
{
	CheckEatenFruit();

	if (HasCollided())
	{
		Die();
	}
}

void Snake::IncrementLength()
{
	m_currentLength++;
	m_bHasSnakeGrown = true;
}

void Snake::UpdatePositionsContainer(const Point2D newPos)
{
	for (int i = m_currentLength - 1; i > 0 ; i--)
	{
		if ((i == m_currentLength - 1) && m_bHasSnakeGrown)
		{
			m_bodyPositions.push_back(m_bodyPositions[i]);
		}
		else
		{
			m_bodyPositions[i] = m_bodyPositions[i - 1];
		}
	}
	m_bodyPositions[0] = newPos;
}

const bool Snake::HasCollided() const
{
	GridManager pGridMan = GridManager::Instance();
	Point2D nextPos = GetNextSquareCoordinate();

	// Has snake left grid?
	if (pGridMan.IsPosOutsideOfGrid(nextPos))
	{
		return true;
	}

	// Has snake bumped into self?
	else if (pGridMan.GetIsSquareOccupied(nextPos) == GridManager::GridObject::kSnake)
	{
		return true;
	}

	return false;
}

void Snake::CheckEatenFruit()
{
	Point2D nextPos = GetNextSquareCoordinate();
	if (GridManager::Instance().GetIsSquareOccupied(nextPos) == GridManager::GridObject::kFruit)
	{
		IncrementLength();
	}
}

const Point2D Snake::GetNextSquareCoordinate() const
{
	Point2D moveVector = Map_MoveVector.at(m_dir);
	return m_bodyPositions[0] + moveVector;
}

void Snake::Die()
{
}
