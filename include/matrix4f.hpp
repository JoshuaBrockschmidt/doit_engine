#ifndef MATRIX4F_H
#define MATRIX4F_H

#include <array>
#include <string>

namespace DOIT {
	class Matrix4f {
	public:
		Matrix4f();
		Matrix4f(const Matrix4f& mat);
		Matrix4f(const std::array<std::array<float, 4>, 4>& _m);
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

		/* Used by DOIT::Transform for the sake of convenience
		 *
		 * @param x Translation on x axis.
		 * @param y Translation on y axis.
		 * @param z Translation on z axis.
		 */
		void initTranslation(float x, float y, float z);

		/* Used by DOIT::Transform for the sake of convenience.
		 *
		 * @param x Rotation on x axis in radians.
		 * @param y Rotation on y axis in radians.
		 * @param z Rotation on z axis in radians.
		 */
		void initRotation(float x, float y, float z);

		/* Used by DOIT::Transform for the sake of convenience.
		 *
		 * @param x Scaling on x axis.
		 * @param y Scaling on y axis.
		 * @param z Scaling on z axis.
		 */
		void initScale(float x, float y, float z);

		/* Used by DOIT::Transform for the sake of convenience.
		 *
		 * @param fov Field of view in degrees.
		 * @param w Width of screen.
		 * @param h Height of screen.
		 * @param zNear How close objects can be before clipping.
		 * @param zFar How far away objects can be before clipping.
		 */
		void initProjection(float fov, float w, float h, float zNear, float zFar);

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
