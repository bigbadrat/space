#ifndef TANAKA_INPUT_HANDLER_COMPONENT_H_
#define TANAKA_INPUT_HANDLER_COMPONENT_H_
#include "base_component.h"
#include "spatial_component.h"


namespace Tanaka
{

class InputHandlerComponent : public BaseComponent
{
public:
    typedef std::shared_ptr<InputHandlerComponent> Ptr;
    InputHandlerComponent();


    void process_input( Event& e );

    static
    Ptr Create();

    virtual
    std::string name() const;

    virtual
    void on_set_owner();

private:
    SpatialComponent* _spatial;
};

} //end namespace Tanaka

#endif
