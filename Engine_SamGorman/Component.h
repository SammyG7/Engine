#pragma once

#include <SDL.h>
#include <unordered_map>
#include <string>

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

	private:
		friend class Entity;
		static std::unordered_map<uint32_t, Derived> componentMap;	
		static Derived& addComponentWithEntityID(uint32_t entityID)
		{
			Derived newComponent;
			componentMap[enitityID] = newComponent;
			return componentMap[entityID];
		}

		static Derived& getComponentWithEntityID(uint32_t entityID)
		{
			return componentMap[entityID];
		}
};

//Template Statistics
template <typename Derived>
std::unordered_map<uint32_t, Derived> Component<Derived>::componentMap;