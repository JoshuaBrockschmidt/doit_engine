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

#include <cmath>
#include "vector3f.hpp"

namespace DOIT {
	Vector3f::Vector3f(float x, float y, float z) {
		setX(x);
		setY(y);
		setZ(z);
	}

	Vector3f::Vector3f(const Vector3f& v) {
		copy(v);
	}

	Vector3f::~Vector3f() {}

	void Vector3f::setX(float _x) {
		x = _x;
	}

	void Vector3f::setY(float _y) {
		y = _y;
	}

	void Vector3f::setZ(float _z) {
		z = _z;
	}

	float Vector3f::getX() const {
		return x;
	}

	float Vector3f::getY() const {
		return y;
	}

	float Vector3f::getZ() const {
		return z;
	}

	float Vector3f::mag() {
		return std::sqrt(x*x + y*y + z*z);
	}

	float Vector3f::dot(const Vector3f& v) {
		return x*v.x + y*v.y + z*v.z;
	}

	Vector3f Vector3f::cross(const Vector3f& v) {
		float _x = y*v.z - z*v.y;

		return Vector3f(y*v.z - z*v.y,
				z*v.x - x*v.z,
				x*v.y - y*v.x );
	}

	Vector3f Vector3f::normalize() {
		return (*this / mag());
	}

	Vector3f Vector3f::rotate(float rads) {
		return Vector3f(0, 0, 0); //TODO
	}

	std::string Vector3f::to_string() {
		return (std::string() + "(" +
			std::to_string(x) + ", " +
			std::to_string(y) + ", " +
			std::to_string(z) + ")" );
	}

	Vector3f Vector3f::operator+(const Vector3f& v) {
		return Vector3f(x + v.x, y + v.y, z + v.z);
	}

	Vector3f Vector3f::operator+(float add) {
		return Vector3f(x + add, y + add, z + add);
	}

	Vector3f Vector3f::operator-(const Vector3f& v) {
		return Vector3f(x - v.x, y - v.y, z - v.z);
	}

	Vector3f Vector3f::operator-(float sub) {
		return Vector3f(x - sub, y - sub, z - sub);
	}

	Vector3f Vector3f::operator*(const Vector3f& v) {
		return Vector3f(x * v.x, y * v.y, z * v.z);
	}

	Vector3f Vector3f::operator*(float m) {
		return Vector3f(x * m, y * m, z * m);
	}

	Vector3f Vector3f::operator/(const Vector3f& v) {
		return Vector3f(x / v.x, y / v.y, z / v.z);
	}

	Vector3f Vector3f::operator/(float d) {
		return Vector3f(x / d, y / d, z / d);
	}

	Vector3f& Vector3f::operator=(const Vector3f& v) {
		copy(v);
		return *this;
	}
		
	Vector3f& Vector3f::operator+=(const Vector3f& v) {
		*this = *this + v;
		return *this;
	}

	Vector3f& Vector3f::operator+=(float add) {
		*this = *this + add;
		return *this;
	}

	Vector3f& Vector3f::operator-=(const Vector3f& v) {
		*this = *this + v;
		return *this;
	}

	Vector3f& Vector3f::operator-=(float sub) {
		*this = *this - sub;
		return *this;
	}

	Vector3f& Vector3f::operator*=(const Vector3f& v) {
		*this = *this * v;
		return *this;
	}

	Vector3f& Vector3f::operator*=(float m) {
		*this = *this * m;
		return *this;
	}

	Vector3f& Vector3f::operator/=(const Vector3f& v) {
		*this = *this / v;
		return *this;
	}

	Vector3f& Vector3f::operator/=(float d) {
		*this = *this / d;
		return *this;
	}

	bool Vector3f::operator==(const Vector3f& v) {
		return (x == v.x && y == v.y && z == v.z);
	}

	bool Vector3f::operator!=(const Vector3f& v) {
		return (x != v.x || y != v.y || z != v.z);
	}

	void Vector3f::copy(const Vector3f& v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}
}
