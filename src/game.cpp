#include "game.hpp"
#include "mesh.hpp"
#include "vector3.hpp"
#include "vertex.hpp"

namespace DOIT {
	namespace Game {
		Mesh* testMesh;

		void init() {
			testMesh = new Mesh();

			Vertex data[] = {
				Vertex(Vector3(-1, -1,  0)),
				Vertex(Vector3(-1,  1,  0)),
				Vertex(Vector3( 0,  1,  0))
			};

			testMesh->addVertices(data);
		}

		void cleanUp() {
			delete testMesh;
		}

		void update() {
			Input::update();
		}

		void render() {
			testMesh->draw();
		}
	}
}
