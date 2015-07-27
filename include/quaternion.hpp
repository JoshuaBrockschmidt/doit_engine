#ifndef QUATERNION_H
#define QUATERNION_H

#include "vector3.hpp"

namespace DOIT {
	class Quaternion {
	public:
		Quaternion(double _x, double _y, double _z, double _w);
		~Quaternion();
		void setX(double _x);
		void setY(double _y);
		void setZ(double _z);
		void setW(double _w);
		double getX() const;
		double getY() const;
		double getZ() const;
		double getW() const;

		/* Returns the magnitude of a quaternion.
		 */
		double mag();

		/* Returns a normalized version of a quaternion.
		 */
		Quaternion normalize();

		/* Returns a conjugated version of a quaternion.
		 */
		Quaternion conjugate();

		Quaternion operator*(const Quaternion& q);
		Quaternion operator*(const Vector3& v);
		Quaternion& operator=(const Quaternion& q);
		Quaternion& operator*=(const Quaternion& q);
		Quaternion& operator*=(const Vector3& v);
	private:
		double x, y, z, w;

		void copy(const Quaternion& q);
	};
}

#endif //QUATERNION_H
