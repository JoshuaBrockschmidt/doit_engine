#include "transform.hpp"

namespace DOIT {
	Transform::Transform():
		translation(0.0f, 0.0f, 0.0f) {}

	Transform::~Transform() {}

	void Transform::setTranslation(Vector3f set) {
		translation = set;
	}

	void Transform::setTranslation(float x, float y, float z) {
		translation = Vector3f(x, y, z);
	}

	Vector3f Transform::getTranslation() {
		return translation;
	}

	Matrix4f Transform::getTransformation() {
		Matrix4f transMat = Matrix4f();
		transMat.initTranslation(translation.getX(),
					 translation.getY(),
					 translation.getZ() );

		return transMat;
	}
}
