add_subdirectory( components )

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
message("Compile again dammit")
set (libs
        tanaka_components
        glu32
        opengl32
        glew32s
        glfw3.lib
    )

add_executable( tanaka ${sources} )
target_link_libraries( tanaka ${libs})
