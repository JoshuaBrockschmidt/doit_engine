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

#ifndef QUATERNION_H
#define QUATERNION_H

#include "vector3f.hpp"

namespace DOIT {
	class Quaternion {
	public:
		Quaternion(float _x, float _y, float _z, float _w);
		~Quaternion();
		void setX(float _x);
		void setY(float _y);
		void setZ(float _z);
		void setW(float _w);
		float getX() const;
		float getY() const;
		float getZ() const;
		float getW() const;

		/* Returns the magnitude of a quaternion.
		 */
		float mag();

		/* Returns a normalized version of a quaternion.
		 */
		Quaternion normalize();

		/* Returns a conjugated version of a quaternion.
		 */
		Quaternion conjugate();

		Quaternion operator*(const Quaternion& q);
		Quaternion operator*(const Vector3f& v);
		Quaternion operator*(float v);
		Quaternion& operator=(const Quaternion& q);
		Quaternion& operator*=(const Quaternion& q);
		Quaternion& operator*=(const Vector3f& v);
		Quaternion& operator*=(float v);
	private:
		float x, y, z, w;

		void copy(const Quaternion& q);
	};
}

#endif //QUATERNION_H
