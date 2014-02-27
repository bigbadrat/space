#include "spatial_component.h"
#include <memory>
#include <iostream>
#include <sstream>

namespace Tanaka
{

SpatialComponent::~SpatialComponent()
{
}

SpatialComponent::Ptr SpatialComponent::Create()
{
    Ptr p( std::make_shared<SpatialComponent>());
    p->_position = Vector3(0,0,0);
    return p;
}

void SpatialComponent::pos(float x, float y, float z)
{
    _position = Vector3(x,y,z);

}

void SpatialComponent::pos(Vector3& pos)
{
    _position = pos;
}

Matrix SpatialComponent::matrix()
{
    //_matrix = glm::rotate
        return _matrix;
}

std::string SpatialComponent::name() 
const
{
    return "spatial";
}

std::string SpatialComponent::internal_to_string()
const
{
    std::ostringstream out;
    out << " pos: (" << pos().x << ","
        << pos().y << "," << pos().z<< ") " ;
    return out.str();
}

}//end namespace tanaka
