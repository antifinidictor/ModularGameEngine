#pragma once
/*
 * GameObject
 * Basic object from which all game objects must inherit
 */

#include "basicTypes.h"

class GameObject : public Listener {
public:
	GameObject(id_t id) {
		m_id = id;
	}
	id_t getId() const { return m_id; }

	bool operator<(const GameObject &obj) {
		return m_id < obj.getId();
	}

private:
	id_t m_id;
};
