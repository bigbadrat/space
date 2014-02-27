#ifndef TANAKA_ENGINE_H_
#define TANAKA_ENGINE_H_

#include <memory>
#include <deque>
#include "game_time.h"
#include "event_manager.h"
#include "input_manager.h"
#include "entity_manager.h"
#include "components/component_manager.h"
#include "renderer.h"

namespace Tanaka
{

class Engine
{
public:
    Engine();

    void init();
    void run();

    static
    Engine& get();

    EntityManager& entity_manager();
    EventManager& event_manager();

    ComponentManager::Ptr get_manager(const std::string& name);
	Renderer& renderer();

    void draw();
private:
    void update(GameTime time);

    static Engine* _instance;
    double _update_frequency;

    GameTime::TimePoint _next_update;
    GameTime::TimePoint _last_update;


    EventManager _event_manager;
    EntityManager _entity_manager;
    Renderer _render;
    InputManager _input;

    typedef std::deque<std::shared_ptr<ComponentManager> > ManagerList;
    ManagerList _managers;
};

} //end namespace


#endif
