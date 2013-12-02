#pragma once
/*
 * Observer
 * An implementation of the Observer pattern.
 */

typedef unsigned int event_t;
#include <map>

class Observer {
public:
	//Generic callback returning some form of status message
	int callback(event_t eventId, void *data);
	bool supportsEvent(event_t eventId);

protected:
	//Types
	typedef int (*Observer::callback_t)(void*);

	//Registering callbacks:
	void registerCallback(event_t eventId, callback_t cb);

private:
	std::map<event_t, callback_t> m_registeredCallbacks;
};
