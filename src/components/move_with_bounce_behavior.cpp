#include "move_with_bounce_behavior.h"
#include "entity.h"

namespace Tanaka
{

    MoveWithBounceBehavior::MoveWithBounceBehavior()
    {
        _speed = Vector3(1,0,0);
    }

    MoveWithBounceBehavior::~MoveWithBounceBehavior()
    {
    }

    void MoveWithBounceBehavior::speed(float x, float y, float z)
    {
        _speed = Vector3(x,y,z);
    }

    void MoveWithBounceBehavior::speed(Vector3& s)
    {
        _speed = s;
    }

    std::string MoveWithBounceBehavior::name() const
    {
        return "movewithbounce";
    }

    MoveWithBounceBehavior::Ptr MoveWithBounceBehavior::Create()
    {
        Ptr mbh = std::make_shared<MoveWithBounceBehavior>();
        return mbh;
    }

    void MoveWithBounceBehavior::on_set_owner()
    {
        _spatial = dynamic_cast<SpatialComponent*>( _owner->get_component("spatial") );
        if (!_spatial)
            std::cout << "There's no spatial component to work with for entity " << owner()->name() << std::endl;
    }

    void MoveWithBounceBehavior::update(GameTime& time)
    {
        Vector3 new_pos = _spatial->pos();
        new_pos = new_pos + _speed;
        //bounce. Dirty, but noe cube size and no window size... yet
        if ( new_pos.x > 30 || new_pos.x < -30)
            _speed.x = -1*_speed.x;
        if ( new_pos.y > 20 || new_pos.y < -20)
            _speed.y = -1*_speed.y;
        _spatial->pos(new_pos);
    }
    
}

