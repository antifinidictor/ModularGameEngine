#pragma once
/*
 * ObjectEngine
 * An abstract base class from which each each engine inherits its object
 * management properties.
 *
 * Engine developers do not need to inherit from this class, but they do
 * need to create these methods.
 */

#include "basicTypes.h"

class GameObject;

class ObjectEngine {
public:
	virtual void add(GameObject *obj, id_t setId) = 0;
	virtual void remove(id_t objId, id_t setId) = 0;
	virtual void useSet(id_t setId) = 0;
};
