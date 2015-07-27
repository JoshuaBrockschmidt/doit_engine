#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>

namespace DOIT {
	class Vector3 {
	public:
		Vector3(double x, double y, double z);
		Vector3(const Vector3& v);
		~Vector3();

		/* Sets the x value of a vector.
		 *
		 * @param _x New x value. 
		 */
		void setX(double _x);

		/* Sets the y value of a vector.
		 *
		 * @param _y New y value. 
		 */
		void setY(double _y);

		/* Sets the z value of a vector.
		 *
		 * @param _z New z value. 
		 */
		void setZ(double _z);

		/* Returns the x value of a vector.
		 */
		double getX() const;

		/* Returns the y value of a vector.
		 */
		double getY() const;

		/* Returns the z value of a vector.
		 */
		double getZ() const;

		/* Returns the magnitude of a vector.
		 */
		double mag();

		/* Returns the dot product of two vectors.
		 *
		 * @param v Second vector.
		 */
		double dot(const Vector3& v);

		/* Returns the cross product of two vectors.
		 *
		 * @param v Second vector.
		 */
		Vector3 cross(const Vector3& v);

		/* Returns a normalized version of a vector.
		 */
		Vector3 normalize();

		/* Returns a rotated version of a vector.
		 * 
		 * @param rads Angle of rotatation in radians.
		 */
		Vector3 rotate(double rads);

		/* Returns a string representation of a vector.
		 */
		std::string to_string();

		Vector3 operator+(const Vector3& v);
		Vector3 operator+(double add);
		Vector3 operator-(const Vector3& v);
		Vector3 operator-(double sub);
		Vector3 operator*(const Vector3& v);
		Vector3 operator*(double m);
		Vector3 operator/(const Vector3& v);
		Vector3 operator/(double d);
		Vector3& operator=(const Vector3& v);
		Vector3& operator+=(const Vector3& v);
		Vector3& operator+=(double add);
		Vector3& operator-=(const Vector3& v);
		Vector3& operator-=(double sub);
		Vector3& operator*=(const Vector3& v);
		Vector3& operator*=(double m);
		Vector3& operator/=(const Vector3& v);
		Vector3& operator/=(double d);
		bool operator==(const Vector3& v);
		bool operator!=(const Vector3& v);
	private:
		double x, y, z;

		void copy(const Vector3& v);
	};
}

#endif //VECTOR3_H
