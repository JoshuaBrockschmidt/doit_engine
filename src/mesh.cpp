/*
 * doit_engine - A 3D Game Engine
 * Copyright (C) 2015 Joshua Brockschmidt
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

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
