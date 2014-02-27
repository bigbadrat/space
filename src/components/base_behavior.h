#ifndef TANAKA_BASE_BEHAVIOR_H
#define TANAKA_BASE_BEHAVIOR_H

#include <map>
#include <list>
#include <iostream>
#include <string>
#include <memory>

namespace Tanaka
{

class Entity;
struct GameTime;
class Message;

class BaseBehavior
{
public:
    typedef std::shared_ptr<BaseBehavior> Ptr;
    
    static
    Ptr Create();

    BaseBehavior();

    ~BaseBehavior();

    virtual
    void receive( Message &m );

    virtual
    void update( GameTime &time );

    std::string name() const;

    Entity* owner();

    void set_owner(Entity* e);

protected:
    std::string _name;
    virtual
    void on_set_owner();

    Entity* _owner;
};


} //end namespace Tanaka
#endif
