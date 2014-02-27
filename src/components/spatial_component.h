#ifndef TANAKA_SPATIAL_COMPONENT_H_
#define TANAKA_SPATIAL_COMPONENT_H_
#include "base_component.h"
#include <glm/glm.hpp>

namespace Tanaka
{

typedef glm::vec3 Vector3;
typedef glm::mat4 Matrix;

//TODO: This is terribly lacking when compared with the spatial component we used to have in xna
class SpatialComponent : public BaseComponent
{
public:
    typedef std::shared_ptr<SpatialComponent> Ptr;

    static
    Ptr Create();

    virtual ~SpatialComponent();

    void pos(float x, float y, float z);
    void pos(Vector3& pos);

    void rotation(float x, float y, float z);

    Matrix matrix();

    Vector3 pos() const;

    virtual 
    std::string name() const;

    virtual
    std::string internal_to_string() const;

private:
    Vector3 _position;
    Vector3 _rotation;
    Matrix _matrix;
};


inline
Vector3 SpatialComponent::pos() const
{
    return _position;
}

}


#endif
