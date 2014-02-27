
#ifndef _TANAKA_UPDATABLE_COMPONENT_MANAGER_H_
#define _TANAKA_UPDATABLE_COMPONENT_MANAGER_H_
#include <deque>
#include <memory>
#include "game_time.h"
#include "component_manager.h"
#include "base_component.h"

namespace Tanaka
{

//TODO: This is a big one. This should probably be implemented with an intrusive list on the component
class BehaviorManager: public ComponentManager
{
public:
    BehaviorManager();

    virtual
    void update(GameTime& time);


};



}

#endif
