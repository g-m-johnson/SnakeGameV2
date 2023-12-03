#pragma once

class SnakeState
{
	enum class State
	{
		STATE_IDLE,

		STATE_MOVENORTH,
		STATE_MOVEEAST,
		STATE_MOVESOUTH,
		STATE_MOVEWEST,
		
		STATE_DEAD,
	};
};

