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
		void addVertices(std::vector<Vertex> vertices);
		void draw();
	private:
		GLuint vao, vbo;
	};
}

#endif //MESH_H
