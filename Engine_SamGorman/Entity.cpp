#include "Entity.h"

//Statistics
std::vector<Entity> Entity::_entityList;

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

std::vector<Entity>& Entity::getEntityList()
{
	return _entityList;
}

Entity& Entity::create()
{
	Entity e;
	_entityList.push_back(e);
	return _entityList.back;
}
