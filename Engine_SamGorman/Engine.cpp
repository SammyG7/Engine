#include "Engine.h"
#include <iostream>


Engine::Engine(void)
{
	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		//Display error messages
		std::cerr<<"Unable to initialize SDL:" << std::endl;
		//Get additional information
		std::cerr<<SDL_GetError() <<std::endl;

		//Display "Press any key to continue"
		system("pause");
		//Exit program and tell OS it failed
		exit(EXIT_FAILURE);
	}

	

	//Create a window
	SDL_Window*window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);

	if(window == nullptr)
	{
		std::cerr<<"Unable to create window" <<std::endl;
		std::cerr<<SDL_GetError() <<std::endl;

		system("pause");
		exit(EXIT_FAILURE);
	}

	//Create Systems
	renderingSystem = new RenderingSystem();
}

Engine::~Engine(void)
{
	//Destroy window
	SDL_DestroyWindow(window);
	//Shutdown SDL
	SDL_Quit();

	//Destroy Systems
	delete renderingSystem;
}

Engine& Engine::getinstance()
{
	static Engine instance; //Garunteed to be created and destroyed properly
	return instance;
}

void Engine::start()
{
	while(!quit)
	{
		update();
	}
}

void Engine::update()
{
	//Check for SDL events(mouse, keyboard, etc)
	//SDL handles all of the events
	SDL_Event e;

	while(SDL_PollEvent(&e) != NULL)
	{
		if(e.type == SDL_QUIT)
		{
			quit = true;
		}

		//Update Systems
		renderingSystem->update();
	}
}


