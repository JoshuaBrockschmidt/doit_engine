#ifndef VERTEX_H
#define VERTEX_H

#include "vector3f.hpp"

namespace DOIT {
	class Vertex {
	public:
		static const int size = 3;

		Vertex(Vector3f v);
		~Vertex();
		void setPos(Vector3f v);
		Vector3f getPos();
		void buffer(double b[3]);
	private:
		Vector3f pos;
	};
}

#endif //VERTEX_H
