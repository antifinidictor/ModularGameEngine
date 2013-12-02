#pragma once
/*
 * ModularGameEngine
 * Since there should only ever be one engine per application, but it should
 * work with multiple engines.  Therefore, it is implemented using templates
 * instead of inheritance.
 *
 * To support modularity, each subengine keeps its own list of references to
 * the objects.  All object creation and initialization should be done through
 * the ModularGameEngine, which will inform the sub engines if the object is
 * relevant to them.
 *
 * All engines should have the following properties:
 * add(GameObject *obj, uint setId)
 *		Adds the object to the specified set of objects.
 * remove(uint objId, uint setId)
 *		Removes the object from the specified set of objects.
 * useSet(uint setid)
 *		Operations should be performed on the specified set of objects.
 *		Different sets could be different screens, different areas, etc.
 */


#include <vector>
#include <set>

class GameObject;

template<class AudioEngine, class PhysicsEngine, class RenderEngine>
class ModularGameEngine
{
public:
	//Called from main.  Do not access elsewhere!
	static void init(AudioEngine *ae, PhysicsEngine *pe, RenderEngine *re) {
		s_instance = new ModularGameEngine(ae, pe, re);
	}

	static void clean() {
		delete s_instance;
		s_instance = NULL;
	}

	void run() {
		//Future editions may use multithreading
	}

	//Publically permissable
	static inline ModularGameEngine *get() { return m_instance; }
	static inline AudioEngine   *AE() { return ae; }
	static inline PhysicsEngine *PE() { return pe; }
	static inline RenderEngine  *RE() { return re; }

	void kill() { m_isRunning = false; }	//Stop the game

private:
	//Helpers
	ModularGameEngine(AudioEngine *ae, PhysicsEngine *pe, RenderEngine *re) {
		m_isRunning = true;
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

	//Private types
	struct Set {
		//Include any set metainformation here

		//The actual objects
		std::set<GameObject *> m_objs;
	};

	//Private static members
	static ModularGameEngine *s_instance;

	//Private members
	std::vector<Set> m_sets;
	AudioEngine   *m_ae;
	RenderEngine  *m_re;
	PhysicsEngine *m_pe;
	bool m_isRunning;
};

