#pragma once

#include <SDL.h>

class Engine
{
	private:		
		Engine(void); //Private constructor		
		~Engine(void); //Private destructor

		//Don't implement
		Engine(Engine& copy); //Hide copy constructor
		Engine(Engine&& other); //Hide move constrcutor
		Engine& operator = (Engine& copy); //Hide assignment operator

		SDL_Window*window;
		bool quit;

	public:
		static Engine& getinstance(void); //Return something that won't change (static)
										  //Return the instance of Engine (Engine&)
		void start(void);
		void update(void);
};

