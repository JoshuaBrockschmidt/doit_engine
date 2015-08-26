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

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "matrix4f.hpp"
#include "vector3f.hpp"

namespace DOIT {
	class Transform {
	public:
		Transform();
		~Transform();
		void setProjection(float _fov, float w, float h, float _zNear, float _zFar);
		void setTranslation(Vector3f set);
		void setTranslation(float x, float y, float z);
		void setRotation(Vector3f set);
		void setRotation(float x, float y, float z);
		void setScale(Vector3f set);
		void setScale(float x, float y, float z);
		Matrix4f getProjectedTransformation();
		Vector3f getTranslation();
		Vector3f getRotation();
		Vector3f getScale();
		Matrix4f getTransformation();
	private:
		// How close and far away an object can be before it clips.
		static float zNear, zFar;
		// Screen size.
		static float width, height;
		// Field of view in degrees.
		static float fov;
		Vector3f translation;
		Vector3f rotation;
		Vector3f scale;
	};
}

#endif //TRANSFORM_H
