add_subdirectory( components )
add_subdirectory( assets )

set (sources 
        main.cpp
        engine.cpp
        input_manager.cpp
        event_manager.cpp
        entity_manager.cpp
        entity.cpp
        renderer.cpp
        io.cpp
    )


set (libs
        tanaka_components
		tanaka_assets
        glu32
        glfw3
        glew32s
        glew32
        opengl32
    )


add_executable( tanaka ${sources} )
target_link_libraries( tanaka ${libs})
