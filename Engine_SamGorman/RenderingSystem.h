#pragma once

#include <SDL.h>
#include <iostream>

//Parent class
#include "ISystem.h"

//Rendering interface
class RenderingSystem : ISystem
{
	public:
		RenderingSystem(SDL_Window* window);
		~RenderingSystem(void);

		void update();

	private:
		SDL_Renderer* renderer;
};

