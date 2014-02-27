#include "behavior_manager.h"

namespace Tanaka
{

    BehaviorManager::BehaviorManager()
    {
        update_priority(200);
        name("behavior");
    }

void BehaviorManager::update(GameTime& time)
{
    for (auto& i: _components)
        i->update(time);

}

}
