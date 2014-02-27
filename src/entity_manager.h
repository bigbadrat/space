#ifndef _TANAKA_ENTITY_MANAGER_H_
#define _TANAKA_ENTITY_MANAGER_H_

#include <deque>
#include <unordered_map>
#include <memory>
#include "entity.h"

namespace Tanaka
{

class EntityManager
{
public:
    EntityManager();

    //TODO: Check how to make this receive directly a shared_ptr 
    void add( Entity::Ptr e);

    Entity::Ptr find(const std::string& name);

    int count() const;

    void dump() const;

private:
    typedef std::deque< Entity::Ptr > EntityContainer;
    typedef std::unordered_map< std::string, Entity::Ptr > EntityNameIndex;
    EntityContainer _entities;
    EntityNameIndex _name_index;

    std::string get_unique_name();

};

} //end namespace Tanaka

#endif
