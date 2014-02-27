
#include <iostream>
#include "message.h"
#include "base_component.h"
#include "game_time.h"
#include "engine.h"

namespace Tanaka
{

BaseComponent::BaseComponent()
{
}

BaseComponent::~BaseComponent()
{

}


void BaseComponent::receive( Message& m ) 
{ 
    std::cout << "received message type " << m.type() << std::endl;
}

void BaseComponent::update( GameTime& t )
{
    std::cout << "*" ;
    std::cout.flush();
}

void BaseComponent::draw( )
{
}

std::string BaseComponent::name() 
const
{
    return "base";
}

Entity* BaseComponent::owner()
{ 
    return _owner;
}

void BaseComponent::set_owner(Entity* e)
{ 
    _owner = e;
    on_set_owner();
}

BaseComponent::Ptr BaseComponent::Create()
{
    //Create the base component
    BaseComponent::Ptr c( new BaseComponent );
    //Auto register the component
    Engine::get().get_manager("component")->add( c );

    return c;
}

void BaseComponent::on_set_owner() 
{}

std::string BaseComponent::internal_to_string() 
const
{
    return "";
}


}
