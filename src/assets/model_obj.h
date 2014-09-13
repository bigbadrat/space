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

 
    const std::string& name() const;
    
    
    ~Model();
private:

	std::vector<glm::vec4> mVertices;
	std::vector<glm::vec3> mNormals;
	std::vector<GLushort> mElements;
	std::vector<glm::vec2> mTexCoords;
    std::string _name;
};


inline
const std::string& Model::name()
const
{
    return _name;
}


} //end namespace Tanaka
#endif
