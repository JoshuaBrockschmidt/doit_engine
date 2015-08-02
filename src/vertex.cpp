#include "vertex.hpp"

namespace DOIT {
	Vertex::Vertex(Vector3 v):
		pos(v) {}

	Vertex::~Vertex() {};

	void Vertex::setPos(Vector3 v) {
		pos = v;
	}

	Vector3 Vertex::getPos() {
		return pos;
	}

	void Vertex::buffer(double b[3]) {
		b[0] = pos.getX();
		b[1] = pos.getY();
		b[2] = pos.getZ();
	}
}
