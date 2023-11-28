#pragma once

#include <cstdint>
#include <vector>
#include "Play.h"

class Snake
{
public:

	enum class Direction
	{
		kNorth, 
		kEast, 
		kSouth, 
		kWest
	};

	std::unordered_map<Direction, Point2D> Map_MoveVector
	{
		{Direction::kNorth, Point2D(0, 1)},
		{Direction::kEast,	Point2D(1, 0)},
		{Direction::kSouth, Point2D(0, -1)},
		{Direction::kWest,	Point2D(-1, 0)}
	};

	Snake();

	void InitialiseSnake();

	void Update();

	void IncrementLength();

	void UpdatePositionsContainer(const Point2D newPos);

	const bool HasCollided() const;

	void CheckEatenFruit();

	const Point2D GetNextSquareCoordinate() const;

	void Die();

private:

	int16_t m_length = 3;

	std::vector<Point2D> m_bodyPositions;

	Point2D m_headPos;
	
	Point2D m_movementDirection = {1, 0};

	bool m_bHasSnakeGrown = false;

	Direction m_dir = Direction::kEast;
};

