
#ifndef _TANAKA_DRAWABLE_COMPONENT_MANAGER_H_
#define _TANAKA_DRAWABLE_COMPONENT_MANAGER_H_
#include <deque>
#include <memory>
#include "game_time.h"
#include "components/component_manager.h"
#include "components/base_component.h"

namespace Tanaka
{

//TODO: This is a big one. This should probably be implemented with an intrusive list on the component
class DrawableManager: public ComponentManager
{
public:
    DrawableManager();

    virtual
    void draw();

};



}

#endif
