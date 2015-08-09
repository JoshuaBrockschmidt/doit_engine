#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <string>

namespace DOIT {
	class Vector3f {
	public:
		Vector3f(float x, float y, float z);
		Vector3f(const Vector3f& v);
		~Vector3f();

		/* Sets the x value of a vector.
		 *
		 * @param _x New x value. 
		 */
		void setX(float _x);

		/* Sets the y value of a vector.
		 *
		 * @param _y New y value. 
		 */
		void setY(float _y);

		/* Sets the z value of a vector.
		 *
		 * @param _z New z value. 
		 */
		void setZ(float _z);

		/* Returns the x value of a vector.
		 */
		float getX() const;

		/* Returns the y value of a vector.
		 */
		float getY() const;

		/* Returns the z value of a vector.
		 */
		float getZ() const;

		/* Returns the magnitude of a vector.
		 */
		float mag();

		/* Returns the dot product of two vectors.
		 *
		 * @param v Second vector.
		 */
		float dot(const Vector3f& v);

		/* Returns the cross product of two vectors.
		 *
		 * @param v Second vector.
		 */
		Vector3f cross(const Vector3f& v);

		/* Returns a normalized version of a vector.
		 */
		Vector3f normalize();

		/* Returns a rotated version of a vector.
		 * 
		 * @param rads Angle of rotatation in radians.
		 */
		Vector3f rotate(float rads);

		/* Returns a string representation of a vector.
		 */
		std::string to_string();

		Vector3f operator+(const Vector3f& v);
		Vector3f operator+(float add);
		Vector3f operator-(const Vector3f& v);
		Vector3f operator-(float sub);
		Vector3f operator*(const Vector3f& v);
		Vector3f operator*(float m);
		Vector3f operator/(const Vector3f& v);
		Vector3f operator/(float d);
		Vector3f& operator=(const Vector3f& v);
		Vector3f& operator+=(const Vector3f& v);
		Vector3f& operator+=(float add);
		Vector3f& operator-=(const Vector3f& v);
		Vector3f& operator-=(float sub);
		Vector3f& operator*=(const Vector3f& v);
		Vector3f& operator*=(float m);
		Vector3f& operator/=(const Vector3f& v);
		Vector3f& operator/=(float d);
		bool operator==(const Vector3f& v);
		bool operator!=(const Vector3f& v);
	private:
		float x, y, z;

		void copy(const Vector3f& v);
	};
}

#endif //VECTOR3F_H
