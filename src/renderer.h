#ifndef TANAKA_RENDERER_H
#define TANAKA_RENDERER_H

#include <deque>
#include <glm/glm.hpp>


struct GLFWwindow;	
namespace Tanaka
{

class Renderer 
{
    public:
        Renderer();
        ~Renderer();

        void init();

        void begin_scene_drawing();
        void end_scene_drawing();

        void update();

		void load_shaders( const std::string& vertex_filename, const std::string& fragment_filename); 

		void set_shader( const std::string& shader_name );


        static
        Renderer* get();

		GLFWwindow* getWindow();

		void set_model_matrix(const glm::mat4& loc);
		void set_diffuse(const glm::vec3& color);
		void set_light_dir(const glm::vec3& dir);

    private:
        static Renderer* _instance;
        int _program;
		GLFWwindow* _window;

		std::deque<int> _shader_list;

		glm::mat4 _view_proj_matrix;
		unsigned int _diffuse;
		unsigned int _mvp;
		unsigned int _model;
		unsigned int _it_model;
		unsigned int _light_dir;
};



}

#endif
