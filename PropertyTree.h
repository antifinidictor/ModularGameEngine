#ifndef PROPERTYTREE_H
#define PROPERTYTREE_H

#include <boost/property_tree/ptree.hpp>
typedef boost::property_tree::ptree PropertyTree;

/* Eventually I may put my own implementation here
class PropertyTree
{
public:
    PropertyTree();
    virtual ~PropertyTree();

    void put(key_t key, int value);
    void put(key_t key, uint value);
    void put(key_t key, std::string value);
protected:
private:
};
*/

#endif // PROPERTYTREE_H
