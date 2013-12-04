#pragma once
/**
 * @class ObjectEngine
 * @author Nathan Heisey
 * @date 12/3/2013
 *
 * An abstract base class from which each each engine inherits its object
 * management properties. Engine developers do not need to inherit from this
 * class, but they do need to implement identical methods.
 *
 * To ensure these methods are minimally accessible, they are protected.
 */

#include "basicTypes.h"
#include "ModularGameEngine.h"

class GameObject;

class ObjectEngine {
public:
    virtual ~ObjectEngine() {}

protected:
    friend ModularGameEngine;

    /** Adds the object to the specified set
     * @param obj   Pointer to the object to be added
     * @param setId ID of the set to which this object should be added
     */
	virtual void add(GameObject *obj, id_t setId) = 0;

	/** Removes the object from the specified set, but does not delete it
	 * @param objId ID of the object to remove
	 * @param setId ID of the set to remove this object from
	 * @return Pointer to the object removed, or NULL if not found
	 */
	virtual GameObject *remove(id_t objId, id_t setId) = 0;

	/** Use the specified set for all engine operations on the next update
	 * cycle
	 * @param setId ID of the set to use
	 */
	virtual void useSet(id_t setId) = 0;
};
