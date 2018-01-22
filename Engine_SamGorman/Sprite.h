#pragma once

#include "Component.h"
#include <string>
#include <SDL.h>

class Sprite: public Component<Sprite>
{
	public:
		std::string texture;
		int width, height;
};


