#pragma once
/**
 * @class Observer
 * @author Nathan Heisey
 * @date 12/3/2013
 *
 * A bastardization of the Observer pattern.  Observer defines a generic event
 * observer supporting up to 2^32 events.  Events are handled by implementing
 * member functions accepting a pointer to some event-specific data and
 * returning a status message.  What data is provided and how the status
 * message is interpreted are completely event dependent.
 *
 * To create your own event, simply choose a unique value of event_t.
 * You may then register the event with the ModularGameEngine and inform the
 * engine when an event occurs, or you may attach observers directly to the
 * event generator.
 */
#include <map>

typedef unsigned int event_t;

class Observer {
public:
	/** Handles all events supported by this Observer.
	 * @param eventId   ID of the event to be handled
	 * @param data      Pointer to event-specific data
	 * @return Event-specific return code, or ERR_EVENT_NOT_SUPPORTED otherwise
	 */
	int callback(event_t eventId, void *data);

	/** Checks whether a specific event is supported by this observer
	 * @param eventId   ID of the event to check
	 * @return true if the event is supported
	 */
	bool supportsEvent(event_t eventId);

protected:
	/** Typedef of event callback that can be registered.  Note that the
	 *  parameter can be any non-function pointer type, but the meaning of the
	 *  parameter and the return value are event-dependent.
     *  @param void *   Data transferred from caller to callee; event dependent
     *  @return Status message returned to caller; event dependent
     */
	typedef int (Observer::*callback_t)(void *);

	/** Supported events must be registered on object initialization.  Events
	 *  registered later may or may not be supported correctly.
	 *  @param eventId  ID of the event this callback should be
	 *                  registered for. If there is a conflict, the new
	 *                  callback will replace the old callback.
	 *  @param cb       Pointer to a member function that will handle
	 *                  the callback.  Must be casted to callback_t.
	 */
	void registerCallback(event_t eventId, callback_t cb);

private:
	std::map<event_t, callback_t> m_registeredCallbacks;
};
