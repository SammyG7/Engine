#include "Entity.h"

//Statistics
std::vector<Entity> Entity::_entityList;

Entity::Entity(size_t ID):_ID(ID), _componentMask(0)
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

size_t Entity::getID()
{
	return _ID;
}

Entity& Entity::create()
{
	Entity e(_entityList.size());
	_entityList.push_back(e);
	return _entityList.back;
}
