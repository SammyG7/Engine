//Main.CPP
//Main Class

#include <SDL.h>
#include <iostream>
#include "Engine.h"

int main(int argc, char *args[])
{
	Engine::getinstance().start();
	return EXIT_SUCCESS;

	/*
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
	
	//Add 2 second delay
	SDL_Delay(2000);
	//Destroy window
	SDL_DestroyWindow(window);
	//Shutdown SDL
	SDL_Quit();

	return 0;
	*/
}

