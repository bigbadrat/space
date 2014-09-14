#include <iostream>
#include <functional>
#include "cube_component.h"
#include "engine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLEW_STATIC
#include <GL/glew.h>

namespace Tanaka
{

// This will identify our vertex buffer

	static GLuint g_vertex_array_id = 0;
	static GLuint g_vertex_buffer_id = 0;
	

static GLfloat g_vertex_buffer_data[] = {
    //lower triangle
   -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    1.0f,  1.0f, 0.0f,
	//upper triangle
   -1.0f, -1.0f, 0.0f,
	1.0f,  1.0f, 0.0f,
   -1.0f,  1.0f, 0.0f
};

static GLuint g_index_buffer_data[] = {
    0,1,2,
    0,2,3,
};

CubeComponent::CubeComponent():
	_color(glm::vec3(1,0,0))
{
	//Check if the vao and vbo were created before
	if ( g_vertex_array_id == 0)
	{
		//Generate the Vertex Array to store everything
		glGenVertexArrays(1,&g_vertex_array_id);
		glBindVertexArray(g_vertex_array_id);

		//Generate and load the data to the vbo
		glGenBuffers(1, &g_vertex_buffer_id);
		glBindBuffer(GL_ARRAY_BUFFER, g_vertex_buffer_id);
		glBufferData(GL_ARRAY_BUFFER,sizeof(g_vertex_buffer_data), g_vertex_buffer_data,GL_STATIC_DRAW);
		
		//For now, we know the attribute 0 is the vertex position.
		glVertexAttribPointer( 0,3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);

		//Unbind the vertex array to prevent accidetal changes from outside
		glBindVertexArray(0);
	}
}
CubeComponent::~CubeComponent()
{
	if (g_vertex_array_id != 0)
	{
		glDeleteVertexArrays( 1, &g_vertex_array_id);
		glDeleteBuffers(1, &g_vertex_buffer_id);
		g_vertex_array_id = 0;
		g_vertex_buffer_id = 0;
	}
}

void CubeComponent::draw()
{
    if (!_spatial)
        std::cerr << "Entity " << owner()->name() << " lost the spatial component to draw the cube!" << std::endl;
	
	//Get the renderer and tell him to use the shader
	Renderer& renderer = Engine::get().renderer();
	renderer.set_shader("easy");
	
	//Move the cube where it should appear
	renderer.set_model_matrix( _spatial->matrix());
	renderer.set_diffuse(_color);
	
	//Activate the vertex array with all the data and ask for drawing
	glBindVertexArray(g_vertex_array_id);
	glDrawArrays(GL_TRIANGLES, 0, 6);

}


CubeComponent::Ptr CubeComponent::Create()
{
    Ptr c= std::make_shared<CubeComponent>();
    Engine::get().get_manager("drawable")->add( c );
    return c;

}

std::string CubeComponent::name() 
const
{
    return "cube";
}

void CubeComponent::on_set_owner()
{
    _spatial = dynamic_cast<SpatialComponent*>( _owner->get_component("spatial") );
    if (!_spatial)
        std::cout << "There's no spatial component to work with for entity " << owner()->name() << std::endl;
}

void CubeComponent::set_color(float r, float g, float b)
{
	_color = glm::vec3(r,g,b);
}

}
