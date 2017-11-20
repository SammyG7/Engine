#pragma once

#include <SDL.h>

class Entity
{
	public:
		Entity(void);
		~Entity(void);

		template <typename C>
		void addComponent()
		{
		}

		template <typename C>
		void removeComponent()
		{
		}
};
