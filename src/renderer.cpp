#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLEW_STATIC
#include <GL/glew.h>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include "renderer.h"
#include "engine.h"


namespace Tanaka
{

Renderer* Renderer::_instance = NULL;

void simple_render()
{
    Engine::get().draw();
}

Renderer::Renderer()
{
    _instance = this;
}

Renderer::~Renderer()
{

}

namespace Util
{
void loadFileContent(const std::string& filename, std::string& content)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open() || !file.good())
		throw std::runtime_error("couldn't open file");
	content.assign( std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()); 

	//std::cout << " Loaded code of file " << filename << ":\n" << content << std::endl;
}

GLuint get_shader_from_file( GLenum type, const std::string& filename)
{
	//Read the file and stoe the source code
	std::string shaderSourceCode;
	loadFileContent(filename, shaderSourceCode );
	std::cout << "Compiling shader " << filename << std::endl;

	//Create the shader and compile it
	GLuint shaderID = glCreateShader(type);
	const char* shaderSourceCodePtr = shaderSourceCode.c_str();
	GLint length = shaderSourceCode.size();
	glShaderSource(shaderID, 1, &shaderSourceCodePtr,&length);
    glCompileShader(shaderID);

	//Check the status of the compilation. Note that i have to allocate
	//a buffer to retrieve the log message
	GLint Result = GL_FALSE;
    int InfoLogLength;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> errorMessage(InfoLogLength);
	glGetShaderInfoLog(shaderID, InfoLogLength, NULL, &errorMessage[0]);
    std::cout << "Compile status: " << &errorMessage[0] << std::endl;
 
	return shaderID;
}

GLuint create_program( GLuint vertexID, GLuint fragmentID)
{
	using std::max;
    std::cout << "Linking program" << std::endl;
    GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexID);
	glAttachShader(programID, fragmentID);
    glLinkProgram(programID);
	
	GLint Result = GL_FALSE;
    int InfoLogLength;
	
	//Check the result of linking
	glGetProgramiv(programID, GL_LINK_STATUS, &Result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> errorMessage( max(InfoLogLength, int(1)) );
    glGetProgramInfoLog(programID, InfoLogLength, NULL, &errorMessage[0]);
    std::cout << "Link status:" << &errorMessage[0] << std::endl;
 
	//When the program is linked, we can delete the shaders
    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);

	return programID;
}

GLuint load_shaders(const std::string& vertex_file_path,const std::string& fragment_file_path)
{
	//Load shaders
	GLuint vertexShaderID = get_shader_from_file(GL_VERTEX_SHADER, vertex_file_path);
	GLuint fragmentShaderID = get_shader_from_file(GL_FRAGMENT_SHADER, fragment_file_path);

    // Create the program and return the handle 
 	return create_program(vertexShaderID, fragmentShaderID);
}
} //end namespace Util


void Renderer::init()
{
	//Initialize glfw
	if (!glfwInit())
        throw std::runtime_error("glfw failed");
	_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!_window)
    {
        glfwTerminate();
        return;
    }
	
	/* Make the window's context current */
    glfwMakeContextCurrent(_window);

	//Initialize glew. GLEW HAS TO BE STARTED THE CONTEXT IS SET!
	if (glewInit() != GLEW_OK)
		throw std::runtime_error("glewInit failed");

	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Initializing shaders....." << std::endl;

	// Enable depth test
	//glEnable(GL_DEPTH_TEST);
	//// Accept fragment if it closer to the camera than the former one
	//glDepthFunc(GL_LESS);
	glCullFace(GL_BACK);

	//Load shaders and get the handle for the uniform parameter
	load_shaders("easy.vsh", "easy.psh");
	//set_shader("easy");
	_mvp = glGetUniformLocation(_shader_list.back(), "ModelViewProj");
	_model = glGetUniformLocation(_shader_list.back(), "Model");
	_diffuse = glGetUniformLocation(_shader_list.back(), "diffuse");
	_light_dir = glGetUniformLocation(_shader_list.back(), "light_dir");

	//Set up a simple camera setting.
	glm::mat4 view = glm::lookAt(glm::vec3(0,0,100), glm::vec3(0,0,0), glm::vec3(0,1,0));
	glm::mat4 proj  = glm::perspective(45.0f,4.0f/3.0f,0.0f,500.0f);
	_view_proj_matrix = proj * view;
		

}
void Renderer::load_shaders(const std::string& vertex_filename, const std::string& fragment_filename)
{
	_shader_list.push_back( Util::load_shaders(vertex_filename, fragment_filename));
	std::cout << "Created shader id:"<< _shader_list.back() << std::endl;
}

void Renderer::set_shader( const std::string& shader_name )
{
	assert( !_shader_list.empty() );
	glUseProgram(_shader_list.back());
	
}


void Renderer::begin_scene_drawing()
{
	//For now, simply clear the background
    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
		set_light_dir(glm::normalize(glm::vec3(0.15f,-1.0f, 0.15f)));

}

void Renderer::end_scene_drawing()
{
    glFlush();
	/* Swap front and back buffers */
	glfwSwapBuffers(_window);

}

void Renderer::update()
{

}

GLFWwindow* Renderer::getWindow()
{
	return _window;
}

Renderer* Renderer::get()
{
    return _instance;
}

void Renderer::set_model_matrix(const glm::mat4& loc)
{
	auto mvp = _view_proj_matrix * loc;
	glUniformMatrix4fv(_mvp,1,false, glm::value_ptr(mvp));
	glUniformMatrix4fv(_model,1,false, glm::value_ptr(loc));
}

void Renderer::set_diffuse(const glm::vec3& color)
{
	glUniform3fv(_diffuse, 1, glm::value_ptr(color));
}

void Renderer::set_light_dir(const glm::vec3& dir)
{
	glUniform3fv(_light_dir, 1, glm::value_ptr(glm::normalize(dir)));
}

}
