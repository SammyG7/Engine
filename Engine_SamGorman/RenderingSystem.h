#pragma once

#include <SDL.h>
#include <iostream>


//Parent class
#include "System.h"

//Rendering interface
class RenderingSystem : System<RenderingSystem>
{
	public:
		RenderingSystem(SDL_Window* window);
		~RenderingSystem(void);

		void update();

	private:
		SDL_Renderer* renderer;
};

