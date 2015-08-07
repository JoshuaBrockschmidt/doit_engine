#ifndef MESH_H
#define MESH_H

#include <GL/gl.h>
#include "vertex.hpp"

namespace DOIT {
	class Mesh {
	public:
		Mesh();
		~Mesh();
		void addVertices(Vertex vertices[], unsigned int len);
		void draw();
	private:
		GLuint vbo;
		int size;
	};
}

#endif //MESH_H
