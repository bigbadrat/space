#ifndef TANAKA_MODEL_OBJ_H_
#define TANAKA_MODEL_OBJ_H_


#include <vector>
#include <deque>
#include <memory>
#include <iosfwd>
#include <glm/glm.hpp>
#define GLEW_STATIC
#include <GL/glew.h>

namespace Tanaka
{

class Model
{
public:
    typedef std::shared_ptr<Model> Ptr;
  

	Model(const std::string& filename);
	virtual ~Model();

 
    const std::string& name() const;
    
    void draw();

	struct Vertex
	{
		glm::vec3 position;
		glm::vec3 normal;
	};

private:

	

	std::vector<Vertex> _vertices;
    std::string _name;
	GLuint _vao;
	GLuint _vbo;
};


inline
const std::string& Model::name()
const
{
    return _name;
}


} //end namespace Tanaka
#endif
