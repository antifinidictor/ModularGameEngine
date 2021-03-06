#pragma once
/**
 * @class ModularGameEngine
 * @author Nathan Heisey
 * @date 12/3/2013
 *
 * Main class tying together the different engines. We recommend using this
 * class as follows:
 *
 * In a visible header:
 *  - typedef the modular game engine with the appropriate template
 *      parameters.  We suggest using the name MGE
 *
 * In the main.cpp file:
 *  - define the static MGE::s_instance variable
 *
 * In the main function:
 *  - instantiate the sub-engines
 *  - call MGE::init(), passing in the sub-engines
 *  - call MGE::run()
 *  - call MGE::clean()
 *
 * That's it!  If the render, physics, and audio engines are implemented
 * correctly, all of the rest of the details should be handled via event
 * handlers!
 *
 * The ModularGameEngine takes care of memory management (object creation and
 * deletion), providing ids for objects, and system/user events.  Render and
 * physics events are handled by the render and physics engines.
 */

#include <vector>
#include <map>
#include "basicTypes.h"

class GameObject;

template<class AudioEngine, class PhysicsEngine, class RenderEngine>
class ModularGameEngine
{
public:
	//Called from main.  Do not access elsewhere!
	static void init(AudioEngine *ae, PhysicsEngine *pe, RenderEngine *re) {
		s_instance = new ModularGameEngine(ae, pe, re);
	}

    /** Cleans the game: Deletes all objects and engines */
	static void clean() {
		delete s_instance;
		s_instance = NULL;
	}

    /** Starts the main game loop */
	static void run() {
	    if(!m_isRunning) {
            m_isRunning = true;
            s_instance->_run();
	    }
	}

	//Publically permissable
	static inline ModularGameEngine *get() { return s_instance; }   /**< gets MGE instance */
	static inline AudioEngine   *AE() { return s_instance->m_ae; }  /**< gets audio engine instance */
	static inline PhysicsEngine *PE() { return s_instance->m_pe; }  /**< gets physics engine instance */
	static inline RenderEngine  *RE() { return s_instance->m_re; }  /**< gets render engine instance */
	static inline GameObjectFactory *FAC() { return &s_instance->m_fac; }   /**< gets object factory */

	void kill() { m_isRunning = false; }    /**< ends the game */

private:
	//Helpers
	ModularGameEngine(AudioEngine *ae, PhysicsEngine *pe, RenderEngine *re) {
		m_isRunning = false;
		m_ae = ae;
		m_pe = pe;
		m_re = re;
	}

	~ModularGameEngine(void) {
		delete m_ae;
		delete m_pe;
		delete m_re;

		m_ae = NULL;
		m_pe = NULL;
		m_re = NULL;
	}

    /** Actual main game loop */
	void _run() {
	    while(m_isRunning) {

	    }
	}

	//Private types
	struct Set {
		//Include any set metainformation here

		//The actual objects
		std::map<id_t, GameObject *> m_objects;
		std::map<id_t, GameObject *> m_updateableObjects;
	};

	//Private static members
	static ModularGameEngine *s_instance;

	//Private members
	std::vector<Set> m_sets;
	AudioEngine   *m_ae;
	RenderEngine  *m_re;
	PhysicsEngine *m_pe;

    //non-pointer members
	GameObjectFactory m_fac;
	bool m_isRunning;
};

