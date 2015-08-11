#ifndef MATRIX4F_H
#define MATRIX4F_H

#include <array>
#include <string>

namespace DOIT {
	class Matrix4f {
	public:
		Matrix4f();
		Matrix4f(const Matrix4f& mat);
		~Matrix4f();

		/* Sets the values of a matrix.
		 *
		 * @param _m 4x4 array of corresponding desired matrix values.
		 */
		void setM(const std::array<std::array<float, 4>, 4> &fill);

		/* Sets the value of a specific matrix position.
		 *
		 * @param x [0, 3].
		 * @param y [0, 3].
		 * @param v New value for specified matrix position.
		 */
		void set(unsigned int x, unsigned int y, float v);

		/* Fills a 4x4 array with corresponding matrix values.
		 */
	        std::array<std::array<float, 4>, 4> getM();

		/* Returns the value of a specific matrix position.
		 *
		 * @param x [0, 3].
		 * @param y [0, 3].
		 * @return Value of specified matrix position.
		 */
		float get(unsigned int x, unsigned int y);

		/* Sets value of a matrix to that of an identity matrix.
		 */
		void initIdentity();

		/* Used by DOIT::Transform::getTransformation for the sake of
		 * convenience.
		 */
		void initTranslation(float x, float y, float z);

		/* Returns a string representation of a matrix.
		 */
		std::string to_string();

		Matrix4f operator+(const Matrix4f& mat);
		Matrix4f operator-(const Matrix4f& mat);
		Matrix4f operator*(const Matrix4f& mat);
		Matrix4f operator*(float mult);
		Matrix4f operator/(float div);
		Matrix4f& operator=(const Matrix4f& mat);
		Matrix4f& operator+=(const Matrix4f& mat);
		Matrix4f& operator-=(const Matrix4f& mat);
		Matrix4f& operator*=(const Matrix4f& mat);
		Matrix4f& operator*=(float mult);
		Matrix4f& operator/=(float div);
	private:
		static std::array<std::array<float, 4>, 4> empty;
		static std::array<std::array<float, 4>, 4> identity;

		std::array<std::array<float, 4>, 4> m;

		void copy(const Matrix4f& mat);
	};
}

#endif //MATRIX4F_H
