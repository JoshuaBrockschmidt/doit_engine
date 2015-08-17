#ifndef QUATERNION_H
#define QUATERNION_H

#include "vector3f.hpp"

namespace DOIT {
	class Quaternion {
	public:
		Quaternion(float _x, float _y, float _z, float _w);
		~Quaternion();
		void setX(float _x);
		void setY(float _y);
		void setZ(float _z);
		void setW(float _w);
		float getX() const;
		float getY() const;
		float getZ() const;
		float getW() const;

		/* Returns the magnitude of a quaternion.
		 */
		float mag();

		/* Returns a normalized version of a quaternion.
		 */
		Quaternion normalize();

		/* Returns a conjugated version of a quaternion.
		 */
		Quaternion conjugate();

		Quaternion operator*(const Quaternion& q);
		Quaternion operator*(const Vector3f& v);
		Quaternion operator*(float v);
		Quaternion& operator=(const Quaternion& q);
		Quaternion& operator*=(const Quaternion& q);
		Quaternion& operator*=(const Vector3f& v);
		Quaternion& operator*=(float v);
	private:
		float x, y, z, w;

		void copy(const Quaternion& q);
	};
}

#endif //QUATERNION_H
