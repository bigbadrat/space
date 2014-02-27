#include "base_behavior.h"
#include "message.h"
#include "game_time.h"
#include "entity.h"
#include "engine.h"

namespace Tanaka
{

    BaseBehavior::BaseBehavior()
    {
    }
    
    BaseBehavior::~BaseBehavior()
    {
    }

    BaseBehavior::Ptr BaseBehavior::Create()
    {
        auto bb = std::make_shared<BaseBehavior>();
        //We register the base behavior with the behavior engine
        //Engine::.get().get_manager("behavior")->add(bb);
        return bb;
    }

    void BaseBehavior::receive( Message &m )
    {
    }

    void BaseBehavior::update( GameTime &time )
    {
    }

    std::string BaseBehavior::name() const
    {
        return "basebehavior";
    }

    Entity* BaseBehavior::owner()
    {
        return _owner;
    }

    void BaseBehavior::set_owner(Entity* e)
    {
        _owner = e;
        on_set_owner();
    }

    void BaseBehavior::on_set_owner()
    {
    }


} //end namespace Tanaka
