#include "transform.hpp"

namespace DOIT {
	Transform::Transform():
		translation(0.0f, 0.0f, 0.0f),
		rotation(0.0f, 0.0f, 0.0f) {}

	Transform::~Transform() {}

	void Transform::setTranslation(Vector3f set) {
		translation = set;
	}

	void Transform::setTranslation(float x, float y, float z) {
		translation = Vector3f(x, y, z);
	}

	void Transform::setRotation(Vector3f set) {
		rotation = set;
	}

	void Transform::setRotation(float x, float y, float z) {
	        rotation = Vector3f(x, y, z);
	}

	Vector3f Transform::getTranslation() {
		return translation;
	}

	Vector3f Transform::getRotation() {
		return rotation;
	}

	Matrix4f Transform::getTransformation() {
		Matrix4f transMat = Matrix4f();
		transMat.initTranslation(translation.getX(),
					 translation.getY(),
					 translation.getZ() );
		Matrix4f rotMat = Matrix4f();
		rotMat.initRotation(rotation.getX(),
				    rotation.getY(),
				    rotation.getZ() );

		return (transMat * rotMat);
	}
}
