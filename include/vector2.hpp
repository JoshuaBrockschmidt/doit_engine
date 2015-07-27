#ifndef VECTOR2_H
#define VECTOR2_H

#include <string>

namespace DOIT {
	class Vector2 {
	public:
		Vector2(double x, double y);
		Vector2(const Vector2& v);
		~Vector2();

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

		/* Returns the x value of a vector.
		 */
		double getX() const;

		/* Returns the y value of a vector.
		 */
		double getY() const;

		/* Returns the magnitude of a vector.
		 */
		double mag();

		/* Returns the dot product of two vectors.
		 *
		 * @param v Second vector.
		 */
		double dot(const Vector2& v);

		/* Returns a normalized version of a vector.
		 */
		Vector2 normalize();

		/* Returns a rotated version of a vector.
		 * 
		 * @param angle Angle (in radians) to rotate by.
		 */
		Vector2 rotate(double angle);

		/* Returns a string representation of a vector.
		 */
		std::string to_string();

		Vector2 operator+(const Vector2& v);
		Vector2 operator+(double add);
		Vector2 operator-(const Vector2& v);
		Vector2 operator-(double sub);
		Vector2 operator*(const Vector2& v);
		Vector2 operator*(double m);
		Vector2 operator/(const Vector2& v);
		Vector2 operator/(double d);
		Vector2& operator=(const Vector2& v);
		Vector2& operator+=(const Vector2& v);
		Vector2& operator+=(double add);
		Vector2& operator-=(const Vector2& v);
		Vector2& operator-=(double sub);
		Vector2& operator*=(const Vector2& v);
		Vector2& operator*=(double m);
		Vector2& operator/=(const Vector2& v);
		Vector2& operator/=(double d);
		bool operator==(const Vector2& v);
		bool operator!=(const Vector2& v);
	private:
		double x, y;

		void copy(const Vector2& v);
	};
}

#endif //VECTOR2_H

