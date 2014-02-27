#ifndef TANAKA_MOVE_WITH_BOUNCE_BEHAVIOR_H
#define TANAKA_MOVE_WITH_BOUNCE_BEHAVIOR_H

#include "base_behavior.h"
#include "spatial_component.h"

namespace Tanaka
{

    //typedef glm::vec3 Vector3;

    class MoveWithBounceBehavior: public BaseBehavior
    {
    public:
        typedef std::shared_ptr<MoveWithBounceBehavior> Ptr;

        MoveWithBounceBehavior();
        ~MoveWithBounceBehavior();

        void speed(float x, float y, float z);
        void speed(Vector3& s);
        Vector3 speed() const;
        static
        Ptr Create();

        virtual
        std::string name() const;
        
        virtual
        void update(GameTime& time);

    private:
        SpatialComponent* _spatial;
        Vector3 _speed;
        virtual
        void on_set_owner();
    };

inline
Vector3 MoveWithBounceBehavior::speed() const
{
    return _speed;
}

} //end namespace Tanaka
#endif
