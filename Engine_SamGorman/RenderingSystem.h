#pragma once

//Parent class
#include "ISystem.h"

//Rendering interface
class RenderingSystem : ISystem
{
	public:
		RenderingSystem(void);
		~RenderingSystem(void);

		void update();
};

