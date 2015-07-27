#include <cmath>
#include "quaternion.hpp"

namespace DOIT {
	Quaternion::Quaternion(double _x, double _y, double _z, double _w) {
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	Quaternion::~Quaternion() {}

	void Quaternion::setX(double _x) {
		x = _x;
	}

	void Quaternion::setY(double _y) {
		y = _y;
	}

	void Quaternion::setZ(double _z) {
		z = _z;
	}

	void Quaternion::setW(double _w) {
		w = _w;
	}

	double Quaternion::getX() const {
		return x;
	}

	double Quaternion::getY() const {
		return y;
	}

	double Quaternion::getZ() const {
		return z;
	}

	double Quaternion::getW() const {
		return w;
	}

	double Quaternion::mag() {
		return std::sqrt(x*x + y*y + z*z + w*w);
	}

	Quaternion Quaternion::normalize() {
		Quaternion res = *this;
		double m = mag();

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

	Quaternion Quaternion::operator*(const Vector3& v) {
		return Quaternion(w*v.getX() + y*v.getZ() - z*v.getY(),
				  w*v.getY() + z*v.getX() - x*v.getZ(),
				  w*v.getZ() + x*v.getY() - y*v.getX(),
				  -x*v.getX() - y*v.getY() - z*v.getZ());
	}

	Quaternion& Quaternion::operator=(const Quaternion& q) {
	        copy(q);
	}

	Quaternion& Quaternion::operator*=(const Quaternion& q) {
		copy(*this * q);
	}

	Quaternion& Quaternion::operator*=(const Vector3& v) {
		copy(*this * v);
	}



	void Quaternion::copy(const Quaternion& q) {
		x = q.x;
		y = q.y;
		z = q.z;
		w = q.w;
	}
}
