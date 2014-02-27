#ifndef TANAKA_EVENT_MANAGER_H_
#define TANAKA_EVENT_MANAGER_H_
#include <functional>
#include <map>
#include <deque>
#include <memory>

namespace Tanaka
{
    struct  Event
    {
        int type;
    };

class EventManager
{
public:
    typedef std::function<void( Event& )> EventHandler;
    EventManager();

    void suscribe(int type, EventHandler handler);
    void publish( Event& e);

private:
    typedef std::map< int , std::shared_ptr<std::deque<EventHandler> > > HandlerMap;
    HandlerMap _handlers;

};



}


#endif
