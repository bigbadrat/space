#include "model_obj.h"

#include <iostream>
#include <fstream>
#include <sstream>


namespace Tanaka
{
	void load_obj(const char* filename, std::vector<glm::vec4> &vertices, std::vector<glm::vec3> &normals, std::vector<GLushort> &elements) 
	{
		std::ifstream in(filename, std::ios::in);
		if (!in.good()) 
		{ 
			std::cerr << "Cannot open " << filename << std::endl; 
			exit(1); 
		}

		std::string line;
		while ( std::getline(in, line) ) 
		{
			if (line.substr(0,2) == "v ") 
			{
				std::istringstream s(line.substr(2));
				glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
				vertices.push_back(v);
			}  
			else if (line.substr(0,2) == "f ") 
			{
				std::istringstream s(line.substr(2));
				GLushort a,b,c;
				s >> a; s >> b; s >> c;
				a--; b--; c--;
				elements.push_back(a); elements.push_back(b); elements.push_back(c);
			}
			else if (line[0] == '#') { /* ignoring this line */ }
			else { /* ignoring this line */ }
		}

		normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));
		for (int i = 0; i < elements.size(); i+=3) {
			GLushort ia = elements[i];
			GLushort ib = elements[i+1];
			GLushort ic = elements[i+2];
			glm::vec3 normal = glm::normalize(glm::cross(
				glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
				glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));
			normals[ia] = normals[ib] = normals[ic] = normal;
		}
	}

Model::Model(const std::string& filename)
{
	load_obj(filename.c_str(), mVertices, mNormals, mElements);
}

Model::~Model()
{
    std::cerr << "Destroying entity " << name() << std::endl;
}

    

} //end namespace Tanaka
