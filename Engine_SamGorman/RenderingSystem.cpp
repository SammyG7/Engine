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
	
	//Initialize SDL2_Image
	int IMG_flags = IMG_INIT_PNG | IMG_INIT_JPG;
	//Error Check - Checks if IMG_flags is a PNG or JPG
	if((IMG_Init(IMG_flags) & IMG_flags) != IMG_flags)
	{
		std::cerr<<"Unable to initialize SDL_image:"<<std::endl;
		std::cerr<<IMG_GetError() <<std::endl;
		system("pause");
	}
}

RenderingSystem::~RenderingSystem(void)
{
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
}

void RenderingSystem::update()
{
	//Clear screen colour magenta (RGBA) A - Opacity
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	//Clear screen
	SDL_RenderClear(renderer);
	//Loop through all entities
	for(Entity& entity: Entity::getEntityList())
	{
		//Check if entity has required components
		if((entity.getComponentMask()& componentMask) == componentMask)
		{
			//Get components
			Position& position = entity.getComponent<Position>();
			Sprite& sprite = entity.getComponent<Sprite>();
			
			//Check to see if sprites texture is loaded
			if(_textureMap.count(sprite.texture) < 1)
			{
				_textureMap[sprite.texture] = _loadTexture(sprite.texture);
			}

			//Set sprite width/ height
			SDL_QueryTexture(_textureMap[sprite.texture], NULL, NULL, &sprite.width, &sprite.height);
			//Create drawing rectangle
			SDL_Rect sourceRect = {0, 0, sprite.width, sprite.height};
			SDL_Rect destRect = {(int)position.x, (int)position.y, sprite.width, sprite.height};

			//Copy sprite texture to screen
			SDL_RenderCopy(renderer, _textureMap[sprite.texture], &sourceRect, &destRect);
		}
	}
	//Update screen
	SDL_RenderPresent(renderer);
}

SDL_Texture* RenderingSystem::_loadTexture(std::string texture)
{
	//Load image at specific path
	SDL_Surface* surface = IMG_Load(texture.c_str());

	if(surface == nullptr)
	{
		std::cerr<<"Unable to load image:"<<texture<<std::endl;
		std::cerr<<IMG_GetError() <<std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	//Create texture from surface pixels
	SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer, surface);

	if(spriteTexture == nullptr)
	{
		std::cerr<<"Unable to create texture from surface:"<<std::endl;
		std::cerr<<SDL_GetError() <<std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	//Get rid of temporary SDL2 surface
	SDL_FreeSurface(surface);
	return spriteTexture;
}