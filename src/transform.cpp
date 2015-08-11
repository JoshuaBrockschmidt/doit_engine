#include "transform.hpp"

namespace DOIT {
	Transform::Transform():
		translation(0.0f, 0.0f, 0.0f),
		rotation(0.0f, 0.0f, 0.0f),
		scale(1.0f, 1.0f, 1.0f) {}

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

	void Transform::setScale(Vector3f set) {
		scale = set;
	}

	void Transform::setScale(float x, float y, float z) {
	        scale = Vector3f(x, y, z);
	}

	Vector3f Transform::getTranslation() {
		return translation;
	}

	Vector3f Transform::getRotation() {
		return rotation;
	}

	Vector3f Transform::getScale() {
		return scale;
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
		Matrix4f scaleMat = Matrix4f();
		scaleMat.initScale(scale.getX(),
				   scale.getY(),
				   scale.getZ() );

		return (transMat * (rotMat * scaleMat));
	}
}
