#pragma once

#include <SDL.h>
#include <type_traits>
#include <vector>

class Entity
{
	public:
		Entity(void);
		~Entity(void);

		template <typename C>
		C& addComponent()
		{
			static_assert(std::is_base_of<Component<C>, C>::value, "ERROR: Can only add component types to entities");
			//Adds whatever is already in _componentMask with getMask (1000 and 0010 becomes 1010). | = or which is how you add binary
			_componentMask = _componentMask | C::getMask();
			//return C::addComponentWithEntityID(_ID);
			return getComponent<C>();
		}
		
		template <typename C>
		C& getComponent()
		{
			static_assert(std::is_base_of<Component<C>, C>::value, "ERROR: Can only get component types from entities!");
			return C::addComponentWithEntityID(_ID);
		}

		template <typename C>
		void removeComponent()
		{
			/*
			static_assert(std::is_base_of<Component<C>, C>::value, "ERROR: Can only remove component types to entities");
			_componentMask = _componentMask ^ C::getMask();
			*/
		}

		/*
		template <typename C>
		void removeComponent()
		{
		}
		*/

		size_t getID();

		//Static Methods
		uint32_t getComponentMask();
		static std::vector<Entity>& getEntityList();
		static Entity& create();

	private:
		Entity();
		Entity(size_t _ID);
		
		size_t _ID;
		uint32_t _componentMask;
		static std::vector<Entity> _entityList;
};
