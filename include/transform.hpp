#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "matrix4f.hpp"
#include "vector3f.hpp"

namespace DOIT {
	class Transform {
	public:
		Transform();
		~Transform();
		void setTranslation(Vector3f set);
		void setTranslation(float x, float y, float z);
		void setRotation(Vector3f set);
		void setRotation(float x, float y, float z);
		void setScale(Vector3f set);
		void setScale(float x, float y, float z);
		Vector3f getTranslation();
		Vector3f getRotation();
		Vector3f getScale();
		Matrix4f getTransformation();
	private:
		Vector3f translation;
		Vector3f rotation;
		Vector3f scale;
	};
}

#endif //TRANSFORM_H
