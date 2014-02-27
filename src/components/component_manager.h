#ifndef _TANAKA_SIMPLE_COMPONENT_MANAGER_H_
#define _TANAKA_SIMPLE_COMPONENT_MANAGER_H_
#include <deque>
#include <memory>
#include "game_time.h"
#include "base_component.h"

namespace Tanaka
{

//TODO: This is a big one. This should probably be implemented with an intrusive list on the component
class ComponentManager
{
public:
    typedef std::shared_ptr<ComponentManager> Ptr;

    ComponentManager();

    void add(BaseComponent::Ptr comp);

    void remove(BaseComponent::Ptr comp);

    virtual
    void update(GameTime& time);

    virtual 
    void draw();

    const std::string& name() const;
    void name(const std::string& the_name);


    void update_priority(int p);
    int update_priority() const;


protected:
    typedef std::deque< std::shared_ptr<BaseComponent> > ComponentList;
    ComponentList _components;

    int _update_priority;
    std::string _name;

};


inline 
int ComponentManager::update_priority()
const
{
    return _update_priority;
}

inline
void ComponentManager::update_priority(int p)
{
    _update_priority = p;
}

inline
const std::string& ComponentManager::name() 
    const
{
    return _name;
}

inline
void ComponentManager::name(const std::string& the_name)
{
    _name = the_name;
}

}

#endif
