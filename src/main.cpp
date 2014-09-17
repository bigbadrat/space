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
#include "components/model_component.h"
#include "assets/model_obj.h"
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

	Model::Ptr first( new Model("space_frigate_6.obj"));
	auto mc = ModelComponent::Create();
	mc->set_model(first);
    //Test entity ftw, followed by a test component
    Entity::Ptr e( Entity::Create() );
    e->name("player");
    BaseComponent::Ptr comp( BaseComponent::Create() );
    auto sc = SpatialComponent::Create();
    auto bec = BehaviorEngineComponent::Create();
    //auto cc = CubeComponent::Create();
    auto ih = InputHandlerComponent::Create();
    sc->pos(0,0,50);
	sc->rotation(90,45,0);
	//cc->set_color(1,0,0);
    e->add(comp);
    e->add(sc);
    e->add(bec);
    //e->add(cc);
	e->add(mc);
    e->add(ih);

	//X+ is to the left of the screen
	//Y+ is up
	//Z+ is to the viewer, Farther inside the screen is z-
    Entity::Ptr e2( Entity::Create() );
    e2->name("prop");
    auto sc2 = SpatialComponent::Create();
    auto bec2 = BehaviorEngineComponent::Create();
    e2->add(sc2);
    e2->add(bec2);
    sc2->pos(0,0,50);
	sc2->scale(10);
    auto cc2 = CubeComponent::Create();
	cc2->set_color(0,1,0);
    e2->add(cc2);
   /* auto mbh = MoveWithBounceBehavior::Create();
    mbh->speed(1, 1, 0);
    bec2->add(mbh);*/

    engine.entity_manager().dump();

    engine.run();

    return 0;
}


