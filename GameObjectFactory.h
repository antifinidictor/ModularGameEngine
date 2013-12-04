#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
/** @class GameObjectFactory
 * @author Nathan Heisey
 * @date 12/3/2013
 *
 * A factory class used by the modular engine.  All objects must register their
 * attributes and be create through the factory class.
 */

 //TODO: Figure out how sets and object IDs factor into all of this!

#include "PropertyTree.h"
#include "GameObject.h"
#include <string>
#include <map>

/** @typedef createFunc_t
 * Factory creator-function type.  All objects should include a create() method
 * matching this signature.
 */
typedef GameObject* (*createFunc_t)(const PropertyTree &, const std::string &);

class GameObjectFactory
{
public:
    /** Assists in building objects */
    class ObjectBuilder {
public:
        /** Sets the specified attribute for this object
         * @param key   Key identifying the attribute to set
         * @param value Value of this particular attribute
         * @return This object builder, so building may continue
         */
        virtual ObjectBuilder &setAttribute(std::string key, std::string value) = 0;

        /** Finishes building the object
         * @param setId ID of the set to which this object should be added
         * @return The newly created GameObject
         */
        virtual GameObject *create(id_t setId) = 0;

        //Included only so destructor operation runs smoothly
        virtual ~ObjectBuilder() {}
    };

    /** Assists in registering classes that can be built */
    class ObjectRegistrar {
    public:
        /** Registers the specified attribute so it can be built later
         * @param name Human-readable attribute name
         * @param key Key for accessing this attribute.  Must be unique among
         *        this object's attributes, but need not be unique among all
         *        object's attributes
         * @param defaultValue Default value for this particular attribute.
         *        Also defines this attribute's type
         * @return This object registrar, so more attributes can be registered.
         */
        virtual ObjectRegistrar &registerAttribute(std::string name, std::string key, std::string defaultValue) = 0;

        //Included only so destructor operation runs smoothly
        virtual ~ObjectRegistrar() {}
    };

    //Constructor/destructor
    GameObjectFactory();
    virtual ~GameObjectFactory();

    /** Begins registering the specified class
     * @param className Name of the class to begin registering
     * @param creator Creator method for this class (generally a static method)
     * @return An object builder that will be used to store parameters used to
     *         build the object. Call its registerAttribute() methods
     */
    ObjectRegistrar &registerClass(std::string className, createFunc_t creator);

    /** Starts the build process for a new object of the specified class
     * @param className Name of the class to start building
     * @return An object builder used to attach parameters to an object before
     *         calling its create method.  Call its setAttribute() methods
     */
    ObjectBuilder &buildObject(std::string className);

private:
    class ObjectFactory : public ObjectBuilder, public ObjectRegistrar {
    public:
        ObjectFactory();
        ObjectFactory(createFunc_t creator);
        virtual ~ObjectFactory();

        //From ObjectBuilder
        virtual ObjectBuilder &setAttribute(std::string key, std::string value);
        virtual GameObject *create(id_t setId);

        //From ObjectRegistrar
        virtual ObjectRegistrar &registerAttribute(std::string name, std::string key, std::string defaultValue);

        void reset();

    private:
        struct Attribute {
            Attribute();
            Attribute(std::string name, std::string defaultValue);
            std::string m_name;
            //std::string m_key;
            std::string m_defaultValue;
            //AttributeType m_type; //TODO: Support multiple types
        };

        createFunc_t m_creator;
        PropertyTree m_params;
        typedef std::map<std::string, Attribute>::iterator attrIter_t;
        std::map<std::string, Attribute> m_registeredAttributes;
    };
    typedef std::map<std::string, ObjectFactory>::iterator facIter_t;
    std::map<std::string, ObjectFactory> m_factories;
};

#endif // GAMEOBJECTFACTORY_H
