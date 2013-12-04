#pragma once
/**
 * @file basicTypes
 * @author Nathan Heisey
 * @date 12/3/2013
 *
 * Common types and common operations on those types
 */
typedef unsigned int uint;
typedef unsigned int id_t;

enum BasicEvents {
	ON_RENDER_UPDATE,
	ON_LOGIC_UPDATE,
	ON_PHYSICS_UPDATE,
	ON_KEY_EVENT,       //All key presses are handled together
	ON_SYSTEM_EVENT,    //System and window events are handled together
    NUM_BASIC_EVENTS
};

enum BasicEventReturns {
	ERR_EVENT_NOT_SUPPORTED = -1
};
