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
