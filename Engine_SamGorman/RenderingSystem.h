#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <unordered_map>
#include <string>

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
		std::unordered_map<std::string, SDL_Texture*> _textureMap;
		SDL_Texture* _loadTexture(std::string texture);	
}; 