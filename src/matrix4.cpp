#include <iostream>
#include "matrix4.hpp"

//TODO: Use row-column format instead of x-y format.

namespace DOIT {
	Matrix4::Matrix4() {
		m = empty;
	}

	Matrix4::Matrix4(const Matrix4& mat) {
		copy(mat);
	}

	Matrix4::~Matrix4() {}

	void Matrix4::setM(const std::array<std::array<double, 4>, 4> &fill) {
	        m = fill;
	}

	void Matrix4::set(unsigned int x, unsigned int y, double v) {
		try {
			m[x][y] = v;
		} catch (std::out_of_range& e) {
			std::cerr << "Matrix4::set: Out of Range error: "
				  << e.what() << std::endl;
		}
	}

	std::array<std::array<double, 4>, 4> Matrix4::getM() {
		std::array<std::array<double, 4>, 4> _m = m;
	        return _m;
	}

	double Matrix4::get(unsigned int x, unsigned int y) {
		try {
			return m[x][y];
		} catch (std::out_of_range& e) {
			std::cerr << "Matrix4::get: Out of Range error: "
				  << e.what() << std::endl;
			return 0;
		}
	}

	void Matrix4::initIdentity() {
		m = identity;
	}

	std::string Matrix4::to_string() {
		//TODO
		return std::string();
	}

	Matrix4 Matrix4::operator+(const Matrix4& mat) {
		Matrix4 res = *this;

		for (int x=0; x<4; x++)
			for (int y=0; y<4; y++)
				res.m[x][y] += mat.m[x][y];

		return res;
	}

	Matrix4 Matrix4::operator-(const Matrix4& mat) {
		Matrix4 res = *this;

		for (int x=0; x<4; x++)
			for (int y=0; y<4; y++)
				res.m[x][y] -= mat.m[x][y];

		return res;
	}

	Matrix4 Matrix4::operator*(const Matrix4& mat) {
		Matrix4 res;

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

	Matrix4 Matrix4::operator*(double mult) {
		Matrix4 res = *this;

	        for (int x=0; x<4; x++)
			for (int y=0; y<4; y++)
				res.m[x][y] *= mult;
	}

	Matrix4 Matrix4::operator/(double div) {
		Matrix4 res = *this;

	        for (int x=0; x<4; x++)
			for (int y=0; y<4; y++)
				res.m[x][y] /= div;

	}

	Matrix4& Matrix4::operator=(const Matrix4& mat) {
	        copy(mat);
	}

	Matrix4& Matrix4::operator+=(const Matrix4& mat) {
		copy(*this + mat);
	}

	Matrix4& Matrix4::operator-=(const Matrix4& mat) {
		copy(*this - mat);
	}

	Matrix4& Matrix4::operator*=(const Matrix4& mat) {
		copy(*this * mat);
	}

	Matrix4& Matrix4::operator*=(double mult) {
		copy(*this * mult);
	}

	Matrix4& Matrix4::operator/=(double div) {
		copy(*this / div);
	}



	std::array<std::array<double, 4>, 4> Matrix4::empty =
		{{{0, 0, 0, 0},
		  {0, 0, 0, 0},
		  {0, 0, 0, 0},
		  {0, 0, 0, 0}}};

	std::array<std::array<double, 4>, 4> Matrix4::identity =
		{{{1, 0, 0, 0},
		  {0, 1, 0, 0},
		  {0, 0, 1, 0},
		  {0, 0, 0, 1}}};

	void Matrix4::copy(const Matrix4& mat) {
		m = mat.m;
	}
}
