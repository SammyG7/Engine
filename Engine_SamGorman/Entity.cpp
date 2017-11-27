#include "Entity.h"


Entity::Entity():_componentMask(0)
{

}


Entity::~Entity(void)
{

}

uint32_t Entity::getComponentMask()
{
	return _componentMask;
}
