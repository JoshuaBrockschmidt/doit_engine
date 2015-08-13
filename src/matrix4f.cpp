#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "matrix4f.hpp"

//TODO: Use row-column format instead of x-y format.

namespace DOIT {
	Matrix4f::Matrix4f() {
		m = empty;
	}

	Matrix4f::Matrix4f(const Matrix4f& mat) {
		copy(mat);
	}

	Matrix4f::Matrix4f(const std::array<std::array<float, 4>, 4>& _m) {
		m = _m;
	}

	Matrix4f::~Matrix4f() {}

	void Matrix4f::setM(const std::array<std::array<float, 4>, 4> &fill) {
	        m = fill;
	}

	void Matrix4f::set(unsigned int x, unsigned int y, float v) {
		try {
			m[x][y] = v;
		} catch (std::out_of_range& e) {
			std::cerr << "Matrix4f::set: Out of Range error: "
				  << e.what() << std::endl;
		}
	}

	std::array<std::array<float, 4>, 4> Matrix4f::getM() {
		std::array<std::array<float, 4>, 4> _m = m;
	        return _m;
	}

	float Matrix4f::get(unsigned int x, unsigned int y) {
		try {
			return m[x][y];
		} catch (std::out_of_range& e) {
			std::cerr << "Matrix4f::get: Out of Range error: "
				  << e.what() << std::endl;
			return 0;
		}
	}

	void Matrix4f::initIdentity() {
		m = identity;
	}

	void Matrix4f::initTranslation(float x, float y, float z) {
		m = {{{1, 0, 0, x},
		      {0, 1, 0, y},
		      {0, 0, 1, z},
		      {0, 0, 0, 1}}};
	}

	void Matrix4f::initRotation(float x, float y, float z) {
		std::array<std::array<float, 4>, 4> _m =
			{{{1,  0,                   0,                 0},
			  {0, (float)std::cos(x), -(float)std::sin(x), 0},
			  {0, (float)std::sin(x),  (float)std::cos(x), 0},
			  {0,  0,                   0,                 1}}};
		Matrix4f rx = Matrix4f(_m);

		_m = {{{(float)std::cos(y), 0, -(float)std::sin(y), 0},
		       { 0,                 1,  0,                  0},
		       {(float)std::sin(y), 0,  (float)std::cos(y), 0},
		       { 0,                 0,   0,                 1}}};
		Matrix4f ry = Matrix4f(_m);

	        _m = {{{(float)std::cos(z), -(float)std::sin(z), 0, 0},
		       {(float)std::sin(z),  (float)std::cos(z), 0, 0},
		       { 0,                  0,                  1, 0},
		       { 0,                  0,                  0, 1}}};
		Matrix4f rz = Matrix4f(_m);

		copy(rz * (ry * rx));
	}

	void Matrix4f::initScale(float x, float y, float z) {
		m = {{{x, 0, 0, 0},
		      {0, y, 0, 0},
		      {0, 0, z, 0},
		      {0, 0, 0, 1}}};
	}

	void Matrix4f::initProjection(float fov, float w, float h, float zNear, float zFar) {
		float ar = w/h; //Aspect ratio
		float tanHalfFOV = (float)std::tan((double)fov*M_PI/360);
		float zRange = zNear-zFar;

		m = {{{1 / (tanHalfFOV*ar), 0,              0,                    0},
		      {0,                   1 / tanHalfFOV, 0,                    0},
		      {0,                   0,              (-zNear-zFar)/zRange, 2*zFar*zNear/zRange},
		      {0,                   0,              1,                    0}}};
	}

	std::string Matrix4f::to_string() {
		//TODO
		return std::string();
	}

	Matrix4f Matrix4f::operator+(const Matrix4f& mat) {
		Matrix4f res = *this;

		for (int x=0; x<4; x++)
			for (int y=0; y<4; y++)
				res.m[x][y] += mat.m[x][y];

		return res;
	}

	Matrix4f Matrix4f::operator-(const Matrix4f& mat) {
		Matrix4f res = *this;

		for (int x=0; x<4; x++)
			for (int y=0; y<4; y++)
				res.m[x][y] -= mat.m[x][y];

		return res;
	}

	Matrix4f Matrix4f::operator*(const Matrix4f& mat) {
		Matrix4f res;

		for (int x=0; x<4; x++) {
			for (int y=0; y<4; y++) {
				res.m[x][y] =
					m[x][0] * mat.m[0][y] +
					m[x][1] * mat.m[1][y] +
					m[x][2] * mat.m[2][y] +
					m[x][3] * mat.m[3][y];
			}
		}

		return res;
	}

	Matrix4f Matrix4f::operator*(float mult) {
		Matrix4f res = *this;

	        for (int x=0; x<4; x++)
			for (int y=0; y<4; y++)
				res.m[x][y] *= mult;
	}

	Matrix4f Matrix4f::operator/(float div) {
		Matrix4f res = *this;

	        for (int x=0; x<4; x++)
			for (int y=0; y<4; y++)
				res.m[x][y] /= div;

	}

	Matrix4f& Matrix4f::operator=(const Matrix4f& mat) {
	        copy(mat);
	}

	Matrix4f& Matrix4f::operator+=(const Matrix4f& mat) {
		copy(*this + mat);
	}

	Matrix4f& Matrix4f::operator-=(const Matrix4f& mat) {
		copy(*this - mat);
	}

	Matrix4f& Matrix4f::operator*=(const Matrix4f& mat) {
		copy(*this * mat);
	}

	Matrix4f& Matrix4f::operator*=(float mult) {
		copy(*this * mult);
	}

	Matrix4f& Matrix4f::operator/=(float div) {
		copy(*this / div);
	}



	std::array<std::array<float, 4>, 4> Matrix4f::empty =
		{{{0, 0, 0, 0},
		  {0, 0, 0, 0},
		  {0, 0, 0, 0},
		  {0, 0, 0, 0}}};

	std::array<std::array<float, 4>, 4> Matrix4f::identity =
		{{{1, 0, 0, 0},
		  {0, 1, 0, 0},
		  {0, 0, 1, 0},
		  {0, 0, 0, 1}}};

	void Matrix4f::copy(const Matrix4f& mat) {
		m = mat.m;
	}
}
