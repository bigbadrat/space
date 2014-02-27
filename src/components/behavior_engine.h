#ifndef TANAKA_BEHAVIOR_ENGINE_H
#define TANAKA_BEHAVIOR_ENGINE_H

#include <string>
#include <deque>
#include "base_component.h"
#include "base_behavior.h"

namespace Tanaka
{

class BehaviorEngineComponent: public BaseComponent
{
public:
    typedef std::shared_ptr<BehaviorEngineComponent> Ptr;
    BehaviorEngineComponent();
    ~BehaviorEngineComponent();
    

    static
    Ptr Create();

    void receive( Message &m );

    void update( GameTime& time );

    void add(BaseBehavior::Ptr bb);

    std::string name() const;

private:
    typedef std::deque<BaseBehavior::Ptr> BehaviorList;
    BehaviorList _behaviors;
};
} //end namespace Tanaka
#endif
