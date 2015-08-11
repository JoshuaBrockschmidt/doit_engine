#ifndef MESH_H
#define MESH_H

#include <vector>
#include <GL/gl.h>
#include "vertex.hpp"

namespace DOIT {
	class Mesh {
	public:
		Mesh();
		~Mesh();
		void addVertices(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
		void draw();
	private:
		GLuint vao, vbo, ibo;
		int size;
	};
}

#endif //MESH_H
