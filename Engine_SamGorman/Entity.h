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
		void addComponent()
		{
			static_assert(std::is_base_of<Component<C>, C>::value, "ERROR: Can only add component types to entities");
			//Adds whatever is already in _componentMask with getMask (1000 and 0010 becomes 1010). | = or which is how you add binary
			_componentMask = _componentMask | C::getMask();
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

		//Static Methods
		uint32_t getComponentMask();
		static std::vector<Entity>& getEntityList();
		static Entity& create();

	private:
		uint32_t _componentMask;
		static std::vector<Entity> _entityList;
};
