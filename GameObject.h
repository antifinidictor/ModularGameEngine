#pragma once
/**
 * @class GameObject
 * @author Nathan Heisey
 * @date 12/3/2013
 *
 * A basic game object from which all game objects must inherit.  It is little
 * more than an observer with an ID.
 */

#include "basicTypes.h"
#include "Observer.h"

class GameObject : public Observer {

    /** Gets the ID of the object */
	id_t getId() const { return m_id; }

	bool operator<(const GameObject &obj) {
		return m_id < obj.getId();
	}

protected:
    /** Protected constructor accepting the ID of the game object */
	GameObject(id_t id) {
		m_id = id;
	}

private:
	id_t m_id;
};
