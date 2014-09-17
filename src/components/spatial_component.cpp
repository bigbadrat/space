#include "spatial_component.h"
#include <memory>
#include <iostream>
#include <sstream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>


namespace Tanaka
{

SpatialComponent::SpatialComponent():
	_matrix(1.0),
	_rotation(0),
	_scale(1.0),
	_dirty(false)
{
}

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
	_dirty = true;

}

void SpatialComponent::pos(Vector3& pos)
{
    _position = pos;
	_dirty = true;
}

void SpatialComponent::rotation(float x, float y, float z)
{
    _rotation = Vector3(glm::radians(x),glm::radians(y),glm::radians(z));
	_dirty = true;

}
void SpatialComponent::scale(float s)
{
    _scale= s;
	_dirty = true;

}

Matrix SpatialComponent::matrix()
{
	if (_dirty)
	{
		
		_matrix = glm::translate(glm::mat4(1.0),_position)*
			glm::scale(glm::mat4(1.0),glm::vec3(_scale))*
			glm::eulerAngleYXZ(_rotation.y, _rotation.x, _rotation.z);
		_dirty = false;
	}
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
