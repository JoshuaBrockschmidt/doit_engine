#ifndef VERTEX_H
#define VERTEX_H

#include "vector3.hpp"

namespace DOIT {
	class Vertex {
	public:
		static const int size = 3;

		Vertex(Vector3 v);
		~Vertex();
		void setPos(Vector3 v);
		Vector3 getPos();
		void buffer(double b[3]);
	private:
		Vector3 pos;
	};
}

#endif //VERTEX_H
