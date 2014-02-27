#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdexcept>
#include <GLFW\glfw3.h>
#include "engine.h"
#include "components/drawable_manager.h"
#include "components/behavior_manager.h"

namespace Tanaka
{
Engine* Engine::_instance = NULL;

Engine::Engine()
{
    _instance = this;
}

Engine& Engine::get()
{
    return *_instance;
}

void Engine::init()
{
    //TODO: initialize component managers? Is it needed? Maybe pass things like expected framerate?
    _update_frequency = 1000.0/30;
    //Setup the timestamps to get the engine loop going
    auto now = GameTime::now();
    std::chrono::milliseconds ms((int)_update_frequency);
    _last_update = now;
    _next_update = now + ms;

    //Add all the managers
    _managers.push_back( std::make_shared<ComponentManager>() );
    _managers.push_back( std::make_shared<BehaviorManager>() );
    _managers.push_back( std::make_shared<DrawableManager>() );

    //And sort them according to the priority
    std::sort( _managers.begin(), _managers.end(), 
            []( const std::shared_ptr<ComponentManager>& a, const std::shared_ptr<ComponentManager>& b) -> bool 
            { return a->update_priority() > b->update_priority(); } 
            );

	/* Initialize the Renderer and input systems*/    
    _render.init();
    _input.init();
}

void Engine::run()
{
    GameTime time;
    
    while (true)
    {
        //I check the current time.
        GameTime::TimePoint now = GameTime::now();
        //Is the current time past the timestamp where i have to update the game?
        //TODO:Check how accurate is this
        if ( now > _next_update )
        {
            //How many seconds have passed since the last update?
            auto secs = std::chrono::duration_cast<std::chrono::duration<double> >(now - _last_update).count();
            //Update the time object.
            time.elapsed_time = secs;
            time.total_time += secs;
            //Call update on everything
            update(time);
            //Call to draw stuff that needs to be drawn
            draw();
            
             /* Poll for and process events (input stuff mostly) */
			glfwPollEvents();

            //Setup next update step.
            std::chrono::milliseconds ms((int)_update_frequency);
            _last_update = now;
            _next_update = now + ms;
        }

    }
}

void Engine::update( GameTime time)
{
    _render.update();
    for(auto& m: _managers)
        m->update( time ); 

}

void Engine::draw( )
{
    _render.begin_scene_drawing();
    for(auto& m: _managers)
        m->draw( ); 
    _render.end_scene_drawing();
}

EntityManager& Engine::entity_manager()
{
    return _entity_manager;
}

EventManager& Engine::event_manager()
{
    return _event_manager;
}

ComponentManager::Ptr Engine::get_manager(const std::string& name)
{
    for(auto& m: _managers)
    {
        if (m->name() == name)
            return m;
    }
    throw std::runtime_error("Asking for nonexistant manager:" + name);

}

Renderer& Engine::renderer()
{
	return _render;
}

} //end namespace Tanaka
