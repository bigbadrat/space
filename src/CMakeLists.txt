
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

add_subdirectory( components )
add_subdirectory( assets )

message("Compile again dammit")
set (libs
        tanaka_components
        glu32
        glfw3
        glew32s
        glew32
        opengl32
    )


add_executable( tanaka ${sources} )
target_link_libraries( tanaka ${libs})
