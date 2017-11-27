#pragma once

#include <SDL.h>

class BaseComponent
{
	protected:
		static uint32_t _componentTypeCount;
};

template <typename Derived>
class Component : BaseComponent 
{
	public:
		static uint32_t getMask()
		{
			//Bitwise shifting _mask by _componentType (1 becomes 10 if we shift by one)
			static uint32_t _mask = 1 << _componentTypeCount++;
			return _mask;
		}
};


