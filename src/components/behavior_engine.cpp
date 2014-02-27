#include "behavior_engine.h"
#include "message.h"
#include <iostream>
#include <engine.h>

namespace Tanaka
{

    BehaviorEngineComponent::BehaviorEngineComponent()
    {
    }

    BehaviorEngineComponent::~BehaviorEngineComponent()
    {
    }

void BehaviorEngineComponent::receive( Message &m )
{
}

void BehaviorEngineComponent::update( GameTime &time)
{
    for (auto& i: _behaviors)
        i->update(time);

}

std::string BehaviorEngineComponent::name() 
const
{
    return "behaviorengine";
}

BehaviorEngineComponent::Ptr BehaviorEngineComponent::Create()
{
    //Create engine
    Ptr bec = std::make_shared<BehaviorEngineComponent>();
    Engine::get().get_manager("behavior")->add(bec);
    return bec;
}

    void BehaviorEngineComponent::add(BaseBehavior::Ptr bb)
    {
        _behaviors.push_back(bb);
        bb->set_owner(owner());
    }

} //end namespace Tanaka
