#include "event_manager.h"
#include <utility>
#include <stdexcept>

namespace Tanaka 
{

    EventManager::EventManager()
    {}

    void EventManager::suscribe(int type, EventHandler handler)
    {
        auto found = _handlers.find(type);
        //First time a handler is created for that event type
        if (found == _handlers.end() )
        {
            auto result = _handlers.insert( std::make_pair( 
                        type, std::make_shared<std::deque<EventHandler> >()
                        )) ;
            if (result.second)
                found = result.first;
            else
                throw std::runtime_error("couldn't insert the handler");
        }
        found->second->push_back(handler);

    }

    void EventManager::publish(Event& e)
    {
        auto found = _handlers.find(e.type);
        if (found == _handlers.end())
            return;
        
        for (auto hndl: *(found->second) )
        {
            hndl(e);
        }
    }





}
