#ifndef MATRIX4_H
#define MATRIX4_H

#include <array>
#include <string>

namespace DOIT {
	class Matrix4 {
	public:
		Matrix4();
		Matrix4(const Matrix4& mat);
		~Matrix4();

		/* Sets the values of a matrix.
		 *
		 * @param _m 4x4 array of corresponding desired matrix values.
		 */
		void setM(const std::array<std::array<double, 4>, 4> &fill);

		/* Sets the value of a specific matrix position.
		 *
		 * @param x [0, 3].
		 * @param y [0, 3].
		 * @param v New value for specified matrix position.
		 */
		void set(unsigned int x, unsigned int y, double v);

		/* Fills a 4x4 array with corresponding matrix values.
		 */
	        std::array<std::array<double, 4>, 4> getM();

		/* Returns the value of a specific matrix position.
		 *
		 * @param x [0, 3].
		 * @param y [0, 3].
		 * @return Value of specified matrix position.
		 */
		double get(unsigned int x, unsigned int y);

		/* Sets value of a matrix to that of an identity matrix.
		 */
		void initIdentity();

		/* Returns a string representation of a matrix.
		 */
		std::string to_string();

		Matrix4 operator+(const Matrix4& mat);
		Matrix4 operator-(const Matrix4& mat);
		Matrix4 operator*(const Matrix4& mat);
		Matrix4 operator*(double mult);
		Matrix4 operator/(double div);
		Matrix4& operator=(const Matrix4& mat);
		Matrix4& operator+=(const Matrix4& mat);
		Matrix4& operator-=(const Matrix4& mat);
		Matrix4& operator*=(const Matrix4& mat);
		Matrix4& operator*=(double mult);
		Matrix4& operator/=(double div);
	private:
		static std::array<std::array<double, 4>, 4> empty;
		static std::array<std::array<double, 4>, 4> identity;

		std::array<std::array<double, 4>, 4> m;

		void copy(const Matrix4& mat);
	};
}

#endif //MATRIX4_H
