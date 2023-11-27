#include "DrawingManager.h"
#include "Play.h"
#include "GridManager.h"
#include <vector>

void DrawingManager::ColourSquare(const int16_t x, const int16_t y)
{
	Point2D squarePos = GridManager::Instance().GetSquareCoordinates(x, y);

	Play::DrawSprite("square", squarePos, 0);
}

void DrawingManager::DrawFruit(const int16_t x, const int16_t y)
{
	Point2D squarePos = GridManager::Instance().GetSquareCoordinates(x, y);

	Play::DrawSprite("fruit", squarePos, 0);
}
