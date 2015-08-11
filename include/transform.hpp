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
		Vector3f getTranslation();
		Matrix4f getTransformation();
	private:
		Vector3f translation;
	};
}

#endif //TRANSFORM_H
