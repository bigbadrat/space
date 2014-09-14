
set( components_sources
        component_manager.cpp
        behavior_manager.cpp
        drawable_manager.cpp
        base_component.cpp
        base_behavior.cpp
        cube_component.cpp
		model_component.cpp
        spatial_component.cpp
        input_handler_component.cpp
        behavior_engine.cpp
        move_with_bounce_behavior.cpp
    )


add_library( tanaka_components ${components_sources} )
