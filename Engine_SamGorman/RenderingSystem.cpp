#include "RenderingSystem.h"
#include "Sprite.h"
#include "Position.h"
#include "Entity.h"

RenderingSystem::RenderingSystem(SDL_Window* window)
{
	//Create SDL2 Renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cerr<<"Unable to create SDL Renderer:"<<std::endl;
		std::cerr<<SDL_GetError() <<std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	componentMask = Position::getMask() | Sprite::getMask();
}

RenderingSystem::~RenderingSystem(void)
{
	SDL_DestroyRenderer(renderer);
}

void RenderingSystem::update()
{
	//Clear screen colour magenta (RGBA) A - Opacity
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	//Clear screen
	SDL_RenderClear(renderer);
	//Loop through all entities
	for(Entity& entity : Entity::getEntityList())
	{
		//Check if entity has required components
		if(componentMask == entity.getComponentMask() & componentMask)
		{
			Position& position = entity.getComponent<Position>();
			Sprite& sprite = entity.getComponent<Sprite>();
		}
	}
	//Update screen
	SDL_RenderPresent(renderer);
}