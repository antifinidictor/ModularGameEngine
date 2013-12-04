/*
 * Observer
 * Method definitions for the Observer base class
 */
#include "Observer.h"
#include "basicTypes.h"
using namespace std;

int
Observer::callback(event_t eventId, void *data) {
	map<event_t, callback_t>::iterator event = m_registeredCallbacks.find(eventId);
	if(event != m_registeredCallbacks.end()) {
		callback_t cb = event->second;
		return (this->*cb)(data);
	}
	return ERR_EVENT_NOT_SUPPORTED;
}

bool
Observer::supportsEvent(event_t eventId) {
	return m_registeredCallbacks.find(eventId) != m_registeredCallbacks.end();
}

void
Observer::registerCallback(event_t eventId, Observer::callback_t cb) {
	m_registeredCallbacks[eventId] = cb;
}
