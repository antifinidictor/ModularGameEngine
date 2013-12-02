#pragma once
/*
 * basicTypes
 * Basic types and their operations are declared here
 */
typedef unsigned int uint;
typedef unsigned int id_t;

enum BasicEvents {
	ON_RENDER,
	ON_UPDATE,
	ON_PHYSICS
};

enum BasicEventReturns {
	ERR_EVENT_NOT_SUPPORTED = -1
};