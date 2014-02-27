#ifndef TANAKA_ENTITY_H_
#define TANAKA_ENTITY_H_

#include "components/base_component.h"
#include <string>
#include <deque>
#include <memory>
#include <iosfwd>


namespace Tanaka
{

class Entity 
{
public:
    typedef std::shared_ptr<Entity> Ptr;
    typedef std::deque<BaseComponent::Ptr> ComponentList;

    static
    Ptr Create();

    BaseComponent* get_component(const std::string& name);

    void add(BaseComponent::Ptr comp);

    void receive(Message& msg);

    const std::string& name() const;
    void name(const std::string& n);

    const ComponentList& components() const;

    ~Entity();
private:
    //Disallow normal creation
    Entity();

    ComponentList _components;
    std::string _name;
};


inline
const std::string& Entity::name()
const
{
    return _name;
}

inline
void Entity::name( const std::string& name)
{
    _name = name;
}

inline
const Entity::ComponentList& Entity::components()
const
{
    return _components;
}


} //end namespace Tanaka
#endif
