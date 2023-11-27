#pragma once

#include <cstdint>
#include <vector>
#include "Play.h"

class Snake
{
public:

	Snake();

	void Update();

	void IncrementLength();

	void HasCollided();

private:

	int16_t m_length = 3;

	std::vector<Point2D> m_bodyPositions;

	Point2D m_headPos;
	
	Point2D m_movementDirection = {1, 0};
};

