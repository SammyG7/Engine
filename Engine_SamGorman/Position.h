#pragma once

#include "Component.h"
#include <SDL.h>

class Position: public Component<Position>
{
	public:
		Position() : x(0.0f), y(0.0f){};
		float x, y;
};

