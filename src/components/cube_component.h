#ifndef TANAKA_CUBE_COMPONENT_H_
#define TANAKA_CUBE_COMPONENT_H_

#include "base_component.h"
#include "spatial_component.h"
#include "event_manager.h"
#include <glm/glm.hpp>

namespace Tanaka
{

class CubeComponent: public BaseComponent
{
public:
    typedef std::shared_ptr<CubeComponent> Ptr;
    CubeComponent();


    void draw();

    static
    Ptr Create();

    virtual
    std::string name() const;

    virtual
    void on_set_owner();

	void set_color(float r, float g, float b);

private:
    SpatialComponent* _spatial;
	glm::vec3 _color;

};


}


#endif
