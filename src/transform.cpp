#include "transform.hpp"

namespace DOIT {
	float Transform::fov = 0.0f;
	float Transform::width = 0.0f;
	float Transform::height = 0.0f;
	float Transform::zNear = 0.0f;
	float Transform::zFar = 0.0f;

	Transform::Transform():
		translation(0.0f, 0.0f, 0.0f),
		rotation(0.0f, 0.0f, 0.0f),
		scale(1.0f, 1.0f, 1.0f) {}

	Transform::~Transform() {}

	void Transform::setProjection(float _fov, float w, float h, float _zNear, float _zFar) {
		Transform::fov = _fov;
		Transform::width = w;
		Transform::height = h;
		Transform::zNear = _zNear;
		Transform::zFar = _zFar;
	}

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

	Matrix4f Transform::getProjectedTransformation() {
		Matrix4f transMat = getTransformation();
		Matrix4f proMat = Matrix4f();
		proMat.initProjection(Transform::fov,
				      Transform::width,
				      Transform::height,
				      Transform::zNear,
				      Transform::zFar );

		return proMat*transMat;
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
