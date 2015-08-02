#include <GL/glew.h>
#include "DOIT.hpp"
#include "mesh.hpp"
#include "renderutil.hpp"

//TODO: Not sure how to use OpenGL VBO buffer thingies. Could cause errors later down the road.

namespace DOIT {
	Mesh::Mesh() {
		if (not RenderUtil::GLEW_wasInit) {
			throw InitError("Cannot create mesh: "
					"OpenGL GLEW extension has not been "
					"initialized yet" );
		}

		glGenBuffers(1, &vbo);
		size = 0;
	}

	Mesh::~Mesh() {
		glDeleteBuffers(1, &vbo);
	}

	void Mesh::addVertices(Vertex vertices[]) {

		size = Vertex::size * sizeof(double);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		double buffer[size][3];
		for (int i=0; i<size; i++) {
			vertices[i].buffer(buffer[i]);
		}
		glBufferData(GL_ARRAY_BUFFER,
			     sizeof(vertices),
			     buffer,
			     GL_STATIC_DRAW );
	}

	void Mesh::draw() {
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0,
				      3,
				      GL_DOUBLE,
				      GL_FALSE,
				      Vertex::size*sizeof(double),
				      0 );

		glDrawArrays(GL_TRIANGLES, 0, size);

		glDisableVertexAttribArray(0);
	}
}
