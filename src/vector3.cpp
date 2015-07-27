#include <cmath>
#include "vector3.hpp"

namespace DOIT {
	Vector3::Vector3(double x, double y, double z) {
		setX(x);
		setY(y);
		setZ(z);
	}

	Vector3::Vector3(const Vector3& v) {
		copy(v);
	}

	Vector3::~Vector3() {}

	void Vector3::setX(double _x) {
		x = _x;
	}

	void Vector3::setY(double _y) {
		y = _y;
	}

	void Vector3::setZ(double _z) {
		z = _z;
	}

	double Vector3::getX() {
		return x;
	}

	double Vector3::getY() {
		return y;
	}

	double Vector3::getZ() {
		return z;
	}

	double Vector3::mag() {
		return std::sqrt(x*x + y*y + z*z);
	}

	double Vector3::dot(const Vector3& v) {
		return x*v.x + y*v.y + z*v.z;
	}

	Vector3 Vector3::cross(const Vector3& v) {
		double _x = y*v.z - z*v.y;

		return Vector3(y*v.z - z*v.y,
			       z*v.x - x*v.z,
			       x*v.y - y*v.x );
	}

	Vector3 Vector3::normalize() {
		return (*this / mag());
	}

	Vector3 Vector3::rotate(double rads) {
		return Vector3(0, 0, 0); //TODO
	}

	std::string Vector3::to_string() {
		return (std::string() + "(" +
			std::to_string(x) + ", " +
			std::to_string(y) + ", " +
			std::to_string(z) + ")" );
	}

	Vector3 Vector3::operator+(const Vector3& v) {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 Vector3::operator+(double add) {
		return Vector3(x + add, y + add, z + add);
	}

	Vector3 Vector3::operator-(const Vector3& v) {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 Vector3::operator-(double sub) {
		return Vector3(x - sub, y - sub, z - sub);
	}

	Vector3 Vector3::operator*(const Vector3& v) {
		return Vector3(x * v.x, y * v.y, z * v.z);
	}

	Vector3 Vector3::operator*(double m) {
		return Vector3(x * m, y * m, z * m);
	}

	Vector3 Vector3::operator/(const Vector3& v) {
		return Vector3(x / v.x, y / v.y, z / v.z);
	}

	Vector3 Vector3::operator/(double d) {
		return Vector3(x / d, y / d, z / d);
	}

	Vector3& Vector3::operator=(const Vector3& v) {
		copy(v);
		return *this;
	}
		
	Vector3& Vector3::operator+=(const Vector3& v) {
		*this = *this + v;
		return *this;
	}

	Vector3& Vector3::operator+=(double add) {
		*this = *this + add;
		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3& v) {
		*this = *this + v;
		return *this;
	}

	Vector3& Vector3::operator-=(double sub) {
		*this = *this - sub;
		return *this;
	}

	Vector3& Vector3::operator*=(const Vector3& v) {
		*this = *this * v;
		return *this;
	}

	Vector3& Vector3::operator*=(double m) {
		*this = *this * m;
		return *this;
	}

	Vector3& Vector3::operator/=(const Vector3& v) {
		*this = *this / v;
		return *this;
	}

	Vector3& Vector3::operator/=(double d) {
		*this = *this / d;
		return *this;
	}

	bool Vector3::operator==(const Vector3& v) {
		return (x == v.x && y == v.y && z == v.z);
	}

	bool Vector3::operator!=(const Vector3& v) {
		return (x != v.x || y != v.y || z != v.z);
	}

	void Vector3::copy(const Vector3& v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}
}
