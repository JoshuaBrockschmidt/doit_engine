#include <cmath>
#include "quaternion.hpp"

namespace DOIT {
	Quaternion::Quaternion(float _x, float _y, float _z, float _w) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	Quaternion::~Quaternion() {}

	void Quaternion::setX(float _x) {
		x = _x;
	}

	void Quaternion::setY(float _y) {
		y = _y;
	}

	void Quaternion::setZ(float _z) {
		z = _z;
	}

	void Quaternion::setW(float _w) {
		w = _w;
	}

	float Quaternion::getX() const {
		return x;
	}

	float Quaternion::getY() const {
		return y;
	}

	float Quaternion::getZ() const {
		return z;
	}

	float Quaternion::getW() const {
		return w;
	}

	float Quaternion::mag() {
		return (float)std::sqrt(x*x + y*y + z*z + w*w);
	}

	Quaternion Quaternion::normalize() {
		Quaternion res = *this;
		float m = mag();

		res.x /= m;
		res.y /= m;
		res.z /= m;
		res.w /= m;

		return res;
	}

	Quaternion Quaternion::conjugate() {
		return Quaternion(-x, -y, -z, w);
	}

	Quaternion Quaternion::operator*(const Quaternion& q) {
		return Quaternion(x*q.w + w*q.x + y*q.z - z*q.y,
				  z*q.w + w*q.y + z*q.x - x*q.z,
				  z*q.w + w*q.z + x*q.y - y*q.x,
				  w*q.w - x*q.x - y*q.y - z*q.z);
	}

	Quaternion Quaternion::operator*(const Vector3f& v) {
		return Quaternion(w*v.getX() + y*v.getZ() - z*v.getY(),
				  w*v.getY() + z*v.getX() - x*v.getZ(),
				  w*v.getZ() + x*v.getY() - y*v.getX(),
				 -x*v.getX() - y*v.getY() - z*v.getZ());
	}

	Quaternion Quaternion::operator*(float v) {
		return Quaternion(x*v, y*v, z*v, w*v);
	}

	Quaternion& Quaternion::operator=(const Quaternion& q) {
	        copy(q);
	}

	Quaternion& Quaternion::operator*=(const Quaternion& q) {
		copy(*this * q);
	}

	Quaternion& Quaternion::operator*=(const Vector3f& v) {
		copy(*this * v);
	}

	Quaternion& Quaternion::operator*=(float v) {
		copy(*this * v);
	}

	void Quaternion::copy(const Quaternion& q) {
		x = q.x;
		y = q.y;
		z = q.z;
		w = q.w;
	}
}
