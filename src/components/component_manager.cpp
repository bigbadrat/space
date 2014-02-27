#include "component_manager.h"

namespace Tanaka
{

ComponentManager::ComponentManager()
{
    update_priority(100);
    name("component");
}

void ComponentManager::add(BaseComponent::Ptr comp)
{
    _components.push_back(comp);

}

void ComponentManager::update(GameTime& time)
{
    //This type of components should not call update. These
    //should be very simple data holders. If they need update probably
    //a new type of manager is needed.
}

void ComponentManager::draw()
{
    //These components should be drawn!
}

}
