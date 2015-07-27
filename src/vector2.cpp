#include <cmath>
#include "vector2.hpp"

namespace DOIT {
	Vector2::Vector2(double x, double y) {
		setX(x);
		setY(y);
	}

	Vector2::Vector2(const Vector2& v) {
		copy(v);
	}

	Vector2::~Vector2() {}

	void Vector2::setX(double _x) {
		x = _x;
	}

	void Vector2::setY(double _y) {
		y = _y;
	}

	double Vector2::getX() const {
		return x;
	}

	double Vector2::getY() const {
		return y;
	}

	double Vector2::mag() {
		return std::sqrt(x*x + y*y);
	}

	double Vector2::dot(const Vector2& v) {
		return x*v.x + y*v.y;
	}

	Vector2 Vector2::normalize() {
		return (*this / mag());
	}

	Vector2 Vector2::rotate(double rads) {
		double cos = std::cos(rads);
		double sin = std::sin(rads);

		return Vector2(x * cos - y * sin, x * sin + y * cos);
	}

	std::string Vector2::to_string() {
		return (std::string() + "(" +
			std::to_string(x) + ", " +
			std::to_string(y) + ")" );
	}

	Vector2 Vector2::operator+(const Vector2& v) {
		return Vector2(x + v.x, y + v.y);
	}

	Vector2 Vector2::operator+(double add) {
		return Vector2(x + add, y + add);
	}

	Vector2 Vector2::operator-(const Vector2& v) {
		return Vector2(x - v.x, y - v.y);
	}

	Vector2 Vector2::operator-(double sub) {
		return Vector2(x - sub, y - sub);
	}

	Vector2 Vector2::operator*(const Vector2& v) {
		return Vector2(x * v.x, y * v.y);
	}

	Vector2 Vector2::operator*(double m) {
		return Vector2(x * m, y * m);
	}

	Vector2 Vector2::operator/(const Vector2& v) {
		return Vector2(x / v.x, y / v.y);
	}

	Vector2 Vector2::operator/(double d) {
		return Vector2(x / d, y / d);
	}

	Vector2& Vector2::operator=(const Vector2& v) {
		copy(v);
		return *this;
	}
		
	Vector2& Vector2::operator+=(const Vector2& v) {
		*this = *this + v;
		return *this;
	}

	Vector2& Vector2::operator+=(double add) {
		*this = *this + add;
		return *this;
	}

	Vector2& Vector2::operator-=(const Vector2& v) {
		*this = *this + v;
		return *this;
	}

	Vector2& Vector2::operator-=(double sub) {
		*this = *this - sub;
		return *this;
	}

	Vector2& Vector2::operator*=(const Vector2& v) {
		*this = *this * v;
		return *this;
	}

	Vector2& Vector2::operator*=(double m) {
		*this = *this * m;
		return *this;
	}

	Vector2& Vector2::operator/=(const Vector2& v) {
		*this = *this / v;
		return *this;
	}

	Vector2& Vector2::operator/=(double d) {
		*this = *this / d;
		return *this;
	}

	bool Vector2::operator==(const Vector2& v) {
		return (x == v.x && y == v.y);
	}

	bool Vector2::operator!=(const Vector2& v) {
		return (x != v.x || y != v.y);
	}

	void Vector2::copy(const Vector2& v) {
		x = v.x;
		y = v.y;
	}
}
