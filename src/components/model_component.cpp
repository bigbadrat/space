#include <iostream>
#include <functional>
#include "model_component.h"
#include "engine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLEW_STATIC
#include <GL/glew.h>

namespace Tanaka
{


ModelComponent::ModelComponent():
	_color(glm::vec3(0,0,1))
{
	//Check if the vao and vbo were created before
	//if ( g_vertex_array_id == 0)
	//{
	//	//Generate the Vertex Array to store everything
	//	glGenVertexArrays(1,&g_vertex_array_id);
	//	glBindVertexArray(g_vertex_array_id);

	//	//Generate and load the data to the vbo
	//	glGenBuffers(1, &g_vertex_buffer_id);
	//	glBindBuffer(GL_ARRAY_BUFFER, g_vertex_buffer_id);
	//	glBufferData(GL_ARRAY_BUFFER,sizeof(g_vertex_buffer_data), g_vertex_buffer_data,GL_STATIC_DRAW);
	//	
	//	//For now, we know the attribute 0 is the vertex position.
	//	glVertexAttribPointer( 0,3, GL_FLOAT, GL_FALSE, 0, 0);
	//	glEnableVertexAttribArray(0);

	//	//Unbind the vertex array to prevent accidetal changes from outside
	//	glBindVertexArray(0);
	//}
}


void ModelComponent::draw()
{
    if (!_spatial )
	{
        std::cerr << "Entity " << owner()->name() << " lost the spatial component to draw!" << std::endl;
		return;
	}
	if(!_model)
	{
	    std::cerr << "Entity " << owner()->name() << " lost the model to draw!" << std::endl;
		return;
	}
	//Get the renderer and tell him to use the shader
	Renderer& renderer = Engine::get().renderer();
	renderer.set_shader("easy");
	
	//Move the cube where it should appear
	//renderer.set_model_matrix( glm::translate(glm::mat4(1.0f), _spatial->pos()) );
	renderer.set_model_matrix( _spatial->matrix() );
	renderer.set_diffuse(_color);
	
	//Activate the vertex array with all the data and ask for drawing
	_model->draw();
	

}


ModelComponent::Ptr ModelComponent::Create()
{
    auto c = std::make_shared<ModelComponent>();
    Engine::get().get_manager("drawable")->add( c );
    return c;

}

std::string ModelComponent::name() 
const
{
    return "model";
}

void ModelComponent::on_set_owner()
{
    _spatial = dynamic_cast<SpatialComponent*>( _owner->get_component("spatial") );
    if (!_spatial)
        std::cout << "There's no spatial component to work with for entity " << owner()->name() << std::endl;
}

void ModelComponent::set_color(float r, float g, float b)
{
	_color = glm::vec3(r,g,b);
}

}
