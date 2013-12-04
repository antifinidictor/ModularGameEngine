#include "GameObjectFactory.h"
using namespace std;

#define OBJ_KEY_BASE "obj"

GameObjectFactory::GameObjectFactory()
{
    //ctor
}

GameObjectFactory::~GameObjectFactory()
{
    //dtor
}

GameObjectFactory::ObjectRegistrar &
GameObjectFactory::registerClass(std::string className, createFunc_t creator) {
    m_factories.insert(pair<std::string, ObjectFactory>(
                            className,
                            ObjectFactory(creator)
                        ));
    facIter_t iter = m_factories.find(className);
    return iter->second;
}

GameObjectFactory::ObjectBuilder &
GameObjectFactory::buildObject(std::string className) {
    //This probably throws an exception if the class is not registered
    return m_factories[className];
}

/*
 * ObjectFactory
 */
GameObjectFactory::ObjectFactory::ObjectFactory() {
    m_creator = NULL;
}

GameObjectFactory::ObjectFactory::ObjectFactory(createFunc_t creator) {
    m_creator = creator;
}

GameObjectFactory::ObjectFactory::~ObjectFactory() {
}

//From ObjectBuilder
GameObjectFactory::ObjectBuilder &
GameObjectFactory::ObjectFactory::setAttribute(std::string key, std::string value) {
    m_params.put(OBJ_KEY_BASE + key, value);
    return *this;
}

GameObject *
GameObjectFactory::ObjectFactory::create(id_t setId) {
    return m_creator(m_params, OBJ_KEY_BASE);
}

//From ObjectRegistrar
GameObjectFactory::ObjectRegistrar &
GameObjectFactory::ObjectFactory::registerAttribute(std::string name, std::string key, std::string defaultValue) {
    m_registeredAttributes.insert(pair<std::string, Attribute>(
                            key,
                            Attribute(name, defaultValue)
                        ));
    return *this;
}

void
GameObjectFactory::ObjectFactory::reset() {
    //Fill property tree with default values
    attrIter_t iter = m_registeredAttributes.begin();
    for(; iter != m_registeredAttributes.end(); ++iter) {
        m_params.put(OBJ_KEY_BASE + iter->first, iter->second.m_defaultValue);
    }
}

/*
 * Attribute
 */
GameObjectFactory::ObjectFactory::Attribute::Attribute() {
}

GameObjectFactory::ObjectFactory::Attribute::Attribute(std::string name, std::string defaultValue) {
    m_name = name;
    //m_key = key;
    m_defaultValue = defaultValue;
}
