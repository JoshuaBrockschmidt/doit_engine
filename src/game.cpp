#include "game.hpp"
#include "mesh.hpp"
#include "resourceloader.hpp"
#include "shader.hpp"
#include "vector3.hpp"
#include "vertex.hpp"

namespace DOIT {
	namespace Game {
		Mesh* testMesh;
		Shader* testShader;

		void init() {
			testMesh = new Mesh();
			testShader = new Shader();

			Vertex data[] = {
				Vertex(Vector3(-1, -1,  0)),
				Vertex(Vector3( 0,  1,  0)),
				Vertex(Vector3( 1, -1,  0))
			};

		        testMesh->addVertices(data, 3);
			testShader->addVertexShader(ResourceLoader::loadShader("basicVertex.vs"));
			testShader->addFragmentShader(ResourceLoader::loadShader("basicFragment.fs"));
			testShader->compileShader();
		}

		void cleanUp() {
			delete testMesh;
			delete testShader;
		}

		void update() {
			Input::update();
		}

		void render() {
			testShader->bind();
			testMesh->draw();
		}
	}
}
