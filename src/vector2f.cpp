#include <cmath>
#include "vector2f.hpp"

namespace DOIT {
	Vector2f::Vector2f(float x, float y) {
		setX(x);
		setY(y);
	}

	Vector2f::Vector2f(const Vector2f& v) {
		copy(v);
	}

	Vector2f::~Vector2f() {}

	void Vector2f::setX(float _x) {
		x = _x;
	}

	void Vector2f::setY(float _y) {
		y = _y;
	}

	float Vector2f::getX() const {
		return x;
	}

	float Vector2f::getY() const {
		return y;
	}

	float Vector2f::mag() {
		return std::sqrt(x*x + y*y);
	}

	float Vector2f::dot(const Vector2f& v) {
		return x*v.x + y*v.y;
	}

	Vector2f Vector2f::normalize() {
		return (*this / mag());
	}

	Vector2f Vector2f::rotate(float rads) {
		double cos = std::cos(rads);
		double sin = std::sin(rads);

		return Vector2f((float)(x*cos - y*sin), (float)(x*sin + y*cos));
	}

	std::string Vector2f::to_string() {
		return (std::string() + "(" +
			std::to_string(x) + ", " +
			std::to_string(y) + ")" );
	}

	Vector2f Vector2f::operator+(const Vector2f& v) {
		return Vector2f(x + v.x, y + v.y);
	}

	Vector2f Vector2f::operator+(float add) {
		return Vector2f(x + add, y + add);
	}

	Vector2f Vector2f::operator-(const Vector2f& v) {
		return Vector2f(x - v.x, y - v.y);
	}

	Vector2f Vector2f::operator-(float sub) {
		return Vector2f(x - sub, y - sub);
	}

	Vector2f Vector2f::operator*(const Vector2f& v) {
		return Vector2f(x * v.x, y * v.y);
	}

	Vector2f Vector2f::operator*(float m) {
		return Vector2f(x * m, y * m);
	}

	Vector2f Vector2f::operator/(const Vector2f& v) {
		return Vector2f(x / v.x, y / v.y);
	}

	Vector2f Vector2f::operator/(float d) {
		return Vector2f(x / d, y / d);
	}

	Vector2f& Vector2f::operator=(const Vector2f& v) {
		copy(v);
		return *this;
	}
		
	Vector2f& Vector2f::operator+=(const Vector2f& v) {
		*this = *this + v;
		return *this;
	}

	Vector2f& Vector2f::operator+=(float add) {
		*this = *this + add;
		return *this;
	}

	Vector2f& Vector2f::operator-=(const Vector2f& v) {
		*this = *this + v;
		return *this;
	}

	Vector2f& Vector2f::operator-=(float sub) {
		*this = *this - sub;
		return *this;
	}

	Vector2f& Vector2f::operator*=(const Vector2f& v) {
		*this = *this * v;
		return *this;
	}

	Vector2f& Vector2f::operator*=(float m) {
		*this = *this * m;
		return *this;
	}

	Vector2f& Vector2f::operator/=(const Vector2f& v) {
		*this = *this / v;
		return *this;
	}

	Vector2f& Vector2f::operator/=(float d) {
		*this = *this / d;
		return *this;
	}

	bool Vector2f::operator==(const Vector2f& v) {
		return (x == v.x && y == v.y);
	}

	bool Vector2f::operator!=(const Vector2f& v) {
		return (x != v.x || y != v.y);
	}

	void Vector2f::copy(const Vector2f& v) {
		x = v.x;
		y = v.y;
	}
}
