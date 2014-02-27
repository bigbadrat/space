#include "entity.h"
#include "engine.h"
#include "entity_manager.h"
#include <iostream>

namespace Tanaka
{

Entity::Entity()
{
}

Entity::~Entity()
{
    std::cerr << "Destroying entity " << name() << std::endl;
}
BaseComponent* Entity::get_component(const std::string& name)
{
    for (auto comp: _components)
    {
        if (comp->name() == name)
            return comp.get();
    }
    return NULL;
}

void Entity::add(BaseComponent::Ptr comp)
{
    _components.push_back(comp);
    comp->set_owner(this);
}

void Entity::receive(Message& msg)
{
    for (auto comp: _components)
        comp->receive(msg);
}

Entity::Ptr Entity::Create()
{
    //Create the entity
    Entity::Ptr e( new Entity );
    //auto register on the entity manager for bookkeeping
    Engine::get().entity_manager().add( e );
    
    return e;
}


} //end namespace Tanaka
