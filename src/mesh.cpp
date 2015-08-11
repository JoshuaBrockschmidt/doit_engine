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
		glGenBuffers(1, &ibo);
	}

	Mesh::~Mesh() {
		glDeleteBuffers(1, &ibo);
		glDeleteBuffers(1, &vbo);
		glDeleteVertexArrays(1, &vao);
	}

	void Mesh::addVertices(std::vector<Vertex> vertices, std::vector<unsigned int> indices) {
		int len = vertices.size();
		GLfloat buf1[len*Vertex::size];
		double prebuf[3];
		for (int i=0; i<len; i++) {
			vertices[i].buffer(prebuf);
			for (int j=0, k=i*Vertex::size; j<Vertex::size; j++, k++)
				buf1[k] = (GLfloat)prebuf[j];
		}

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER,
			     sizeof(buf1),
			     buf1,
			     GL_STATIC_DRAW );

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			     sizeof(unsigned int)*indices.size(),
			     &indices[0],
			     GL_STATIC_DRAW );

		size = indices.size();
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

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

		glDisableVertexAttribArray(0);
	}
}
