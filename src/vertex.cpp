#include "vertex.hpp"

namespace DOIT {
	Vertex::Vertex(Vector3f v):
		pos(v) {}

	Vertex::~Vertex() {};

	void Vertex::setPos(Vector3f v) {
		pos = v;
	}

	Vector3f Vertex::getPos() {
		return pos;
	}

	void Vertex::buffer(double b[3]) {
		b[0] = pos.getX();
		b[1] = pos.getY();
		b[2] = pos.getZ();
	}
}
