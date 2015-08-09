#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <string>

namespace DOIT {
	class Vector2f {
	public:
		Vector2f(float x, float y);
		Vector2f(const Vector2f& v);
		~Vector2f();

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

		/* Returns the x value of a vector.
		 */
		float getX() const;

		/* Returns the y value of a vector.
		 */
		float getY() const;

		/* Returns the magnitude of a vector.
		 */
		float mag();

		/* Returns the dot product of two vectors.
		 *
		 * @param v Second vector.
		 */
		float dot(const Vector2f& v);

		/* Returns a normalized version of a vector.
		 */
		Vector2f normalize();

		/* Returns a rotated version of a vector.
		 * 
		 * @param angle Angle (in radians) to rotate by.
		 */
		Vector2f rotate(float angle);

		/* Returns a string representation of a vector.
		 */
		std::string to_string();

		Vector2f operator+(const Vector2f& v);
		Vector2f operator+(float add);
		Vector2f operator-(const Vector2f& v);
		Vector2f operator-(float sub);
		Vector2f operator*(const Vector2f& v);
		Vector2f operator*(float m);
		Vector2f operator/(const Vector2f& v);
		Vector2f operator/(float d);
		Vector2f& operator=(const Vector2f& v);
		Vector2f& operator+=(const Vector2f& v);
		Vector2f& operator+=(float add);
		Vector2f& operator-=(const Vector2f& v);
		Vector2f& operator-=(float sub);
		Vector2f& operator*=(const Vector2f& v);
		Vector2f& operator*=(float m);
		Vector2f& operator/=(const Vector2f& v);
		Vector2f& operator/=(float d);
		bool operator==(const Vector2f& v);
		bool operator!=(const Vector2f& v);
	private:
		float x, y;

		void copy(const Vector2f& v);
	};
}

#endif //VECTOR2F_H

