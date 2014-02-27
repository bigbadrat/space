#include <iostream>
#include <functional>
#include "engine.h"
#include "input_handler_component.h"


namespace Tanaka
{
InputHandlerComponent::InputHandlerComponent()
{}

InputHandlerComponent::Ptr InputHandlerComponent::Create()
{
    Ptr c= std::make_shared<InputHandlerComponent>();
    Engine::get().get_manager("component")->add( c );
    return c;

}

void InputHandlerComponent::process_input( Event& e )
{
    Vector3 pos = _spatial->pos();
    switch (e.type)
    {
        case 4:
            pos.x -= 0.5f;
            break;
        case 6:
            pos.x += 0.5f;
            break;
        case 8:
            pos.y += 0.5;
            break;
        case 2:
            pos.y -= 0.5;
            break;
    }
    _spatial->pos( pos );

}

void InputHandlerComponent::on_set_owner()
{
    using namespace std::placeholders;

    _spatial = dynamic_cast<SpatialComponent*>( _owner->get_component("spatial") );
    if (!_spatial)
        std::cout << "There's no spatial component to work with for entity " << owner()->name() << std::endl;

    Engine::get().event_manager().suscribe( 2, std::bind(&InputHandlerComponent::process_input, this,_1));
    Engine::get().event_manager().suscribe( 4, std::bind(&InputHandlerComponent::process_input, this,_1));
    Engine::get().event_manager().suscribe( 6, std::bind(&InputHandlerComponent::process_input, this,_1));
    Engine::get().event_manager().suscribe( 8, std::bind(&InputHandlerComponent::process_input, this,_1));
}

std::string InputHandlerComponent::name() 
const
{
    return "input_handler";
}

}//end namespace tanaka
