#ifndef TANAKA_COMPONENT_H_
#define TANAKA_COMPONENT_H_
#include <string>
#include <memory>
#include <iosfwd>

namespace Tanaka
{

class Entity;
struct GameTime;
class Message;

class BaseComponent
{
public:
    typedef std::shared_ptr<BaseComponent> Ptr;

    static
    Ptr Create();

    virtual ~BaseComponent();

    virtual 
    void receive( Message& m ); 
    
    virtual 
    void update( GameTime& t ); 

    virtual
    void draw();

    virtual
    std::string name() const;

    virtual
    std::string internal_to_string() const;

    Entity* owner();

    void set_owner(Entity* e);

    //Should not be here. Only till we solve inheritance issue
    BaseComponent();

protected:
    //Disallow normal creation
    //BaseComponent();
    virtual
    void on_set_owner();

    Entity* _owner;

};


} //end namespace Tanaka
#endif
