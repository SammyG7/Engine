#include "Component.h"

uint32_t Component::getMask()
{
	static uint32_t _mask = 0;

	return _mask++;
}