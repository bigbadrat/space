#include "model_obj.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>


namespace Tanaka
{
	void load_obj(const char* filename, std::vector<Model::Vertex> &vertices, std::vector<glm::vec3> &normals, std::vector<glm::vec2> &uvs, 
		std::vector<GLuint> &vertexIndices, std::vector<GLuint> &normalIndices,std::vector<GLuint> &uvIndices) 
	{
		std::ifstream in(filename, std::ios::in);
		if (!in.good()) 
		{ 
			std::cerr << "Cannot open " << filename << std::endl; 
			exit(1); 
		}
		std::vector<glm::vec3> tmp_vertices;
		std::string line;
		while ( std::getline(in, line) ) 
		{
			std::istringstream sline( line );
			std::string type;
			sline >> type;
			if (type == "v") //Reading a vertex
			{ 
				float x,y,z;
				sline >> x >> y >> z;
				tmp_vertices.emplace_back(x,y,z);
			}  
			else if (type == "vn") //Reading a normal
			{
				float x,y,z;
				sline >> x >> y >> z;
				normals.push_back(glm::normalize(glm::vec3(x,y,z)));
			}
			else if (type == "vt") //Reading a vertex texture coordinate
			{
				float u,v;
				sline >> u >> v;
				uvs.emplace_back(u,v);
			}
			else if (type == "f") //Reading a face definition
			{
				unsigned int vertex_id,normal_id,uv_id;
				std::string face_def;
				int count = 0;
				//all faces should have 3 vertices, and each vertex has an index for position, normal and uv
				do 	{
					sline >> face_def; 

					int matches = sscanf_s(face_def.c_str(),"%d/%d/%d", 
											 &vertex_id, &uv_id, &normal_id );					
					++count;
					vertexIndices.push_back(vertex_id);
					normalIndices.push_back(normal_id);
					uvIndices.push_back(uv_id);
					
				} while (!sline.eof());
				if (count != 3)
						throw std::runtime_error("Couldn't parse face definition");
			}
			else if (type == "#") { /* ignoring this line */ }
			else { /* ignoring this line */ }
		}

		for( size_t i = 0; i < vertexIndices.size(); ++i)
		{
			Model::Vertex aux;
			aux.position = tmp_vertices[vertexIndices[i]-1];
			aux.normal = normals[normalIndices[i] -1];

			vertices.push_back( aux );
		}
		

	}

Model::Model(const std::string& filename)
{
	
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> tex_coords;
	std::vector<GLuint> vertex_indices;
	std::vector<GLuint> normal_indices;
	std::vector<GLuint> uv_indices;
	load_obj(filename.c_str(), _vertices, normals, tex_coords, vertex_indices, normal_indices, uv_indices);

	//Generate the Vertex Array to store everything
	glGenVertexArrays(1,&_vao);
	glBindVertexArray(_vao);

	//Generate and load the data to the vbo
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER,_vertices.size()*sizeof(Model::Vertex), &_vertices[0],GL_STATIC_DRAW);
		
	//For now, we know the attribute 0 is the vertex position.
	glVertexAttribPointer( 0,3, GL_FLOAT, GL_FALSE, sizeof(Model::Vertex), 0);
	glVertexAttribPointer( 1,3, GL_FLOAT, GL_FALSE, sizeof(Model::Vertex), (void*)sizeof(glm::vec3));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//Unbind the vertex array to prevent accidetal changes from outside
	glBindVertexArray(0);
}

Model::~Model()
{
    std::cerr << "Destroying asset " << name() << std::endl;
	glDeleteVertexArrays( 1, &_vao);
	glDeleteBuffers( 1, &_vbo);
}

void Model::draw()
{
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES,0, _vertices.size());
}

    

} //end namespace Tanaka
