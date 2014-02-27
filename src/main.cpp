#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "components/base_component.h"
#include "components/spatial_component.h"
#include "components/cube_component.h"
#include "components/input_handler_component.h"
#include "components/behavior_engine.h"
#include "components/move_with_bounce_behavior.h"
#include "entity.h"
#include "message.h"
#include "engine.h"
#include "io.h"

int main()
{
    using namespace Tanaka;
    std::cout << "hello" << std::endl;

    //Engine is the first thing we have to create, or else everything else goes
    //down the crapper
    Engine engine;
    engine.init();

    //Test entity ftw, followed by a test component
    Entity::Ptr e( Entity::Create() );
    e->name("player");
    BaseComponent::Ptr comp( BaseComponent::Create() );
    auto sc = SpatialComponent::Create();
    auto bec = BehaviorEngineComponent::Create();
    auto cc = CubeComponent::Create();
    auto ih = InputHandlerComponent::Create();
    sc->pos(0,0,50);
	cc->set_color(1,0,0);
    e->add(comp);
    e->add(sc);
    e->add(bec);
    e->add(cc);
    e->add(ih);

    Entity::Ptr e2( Entity::Create() );
    e2->name("prop");
    auto sc2 = SpatialComponent::Create();
    auto bec2 = BehaviorEngineComponent::Create();
    e2->add(sc2);
    e2->add(bec2);
    sc2->pos(20,0,50);
    auto cc2 = CubeComponent::Create();
	cc2->set_color(0,1,0);
    e2->add(cc2);
    auto mbh = MoveWithBounceBehavior::Create();
    mbh->speed(1, 1, 0);
    bec2->add(mbh);

    engine.entity_manager().dump();

    engine.run();

    return 0;
}


