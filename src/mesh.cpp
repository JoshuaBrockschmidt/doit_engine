#include <GL/glew.h>
#include "DOIT.hpp"
#include "mesh.hpp"
#include "renderutil.hpp"

namespace DOIT {
	Mesh::Mesh() {
		if (not RenderUtil::GLEW_wasInit) {
			throw InitError("Cannot create mesh: "
					"OpenGL GLEW extension has not been "
					"initialized yet" );
		}

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &vbo);

		size = Vertex::size * sizeof(double);
	}

	Mesh::~Mesh() {
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
	}

	void Mesh::addVertices(Vertex vertices[], unsigned int len) {
		GLfloat buffer[len*Vertex::size];
		double prebuf[3];
		for (int i=0; i<len; i++) {
			vertices[i].buffer(prebuf);
			for (int j=0, k=i*Vertex::size; j<Vertex::size; j++, k++)
				buffer[k] = (GLfloat)prebuf[j];
		}

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER,
			     sizeof(buffer),
			     buffer,
			     GL_STATIC_DRAW );
	}

	void Mesh::draw() {
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0,
				      3,
				      GL_FLOAT,
				      GL_FALSE,
				      0,
				      (GLvoid*)0 );

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(0);
	}
}
