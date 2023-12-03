#pragma once

constexpr int DISPLAY_WIDTH = 720;
constexpr int DISPLAY_HEIGHT = 720;
constexpr int DISPLAY_SCALE = 1;

class Snake;

struct GameState
{
	float m_totalTime;
	float m_updateTimer;
	Snake* m_snake;
};