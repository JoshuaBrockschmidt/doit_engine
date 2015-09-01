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

#include "vertex.hpp"

namespace DOIT {
	Vertex::Vertex(Vector3f v):
		pos(v) {}

	Vertex::Vertex(float x, float y, float z):
		pos(x, y, z) {}

	Vertex::~Vertex() {};

	void Vertex::setPos(Vector3f v) {
		pos = v;
	}

	Vector3f Vertex::getPos() {
		return pos;
	}

	void Vertex::buffer(double b[3]) {
		b[0] = pos.getX();
		b[1] = pos.getY();
		b[2] = pos.getZ();
	}
}
