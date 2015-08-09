#include <cmath>
#include "game.hpp"
#include "mesh.hpp"
#include "resourceloader.hpp"
#include "shader.hpp"
#include "time.hpp"
#include "vector3f.hpp"
#include "vertex.hpp"

namespace DOIT {
	namespace Game {
		Mesh* testMesh;
		Shader* testShader;

		void init() {
			testMesh = new Mesh();
			testShader = new Shader();

			Vertex data[] = {
				Vertex(Vector3f(-1, -1,  0)),
				Vertex(Vector3f( 0,  1,  0)),
				Vertex(Vector3f( 1, -1,  0))
			};

		        testMesh->addVertices(data, 3);
			testShader->addVertexShader(ResourceLoader::loadShader("basicVertex.vs"));
			testShader->addFragmentShader(ResourceLoader::loadShader("basicFragment.fs"));
			testShader->compileShader();

			testShader->addUniform("maxClamp");
		}

		void cleanUp() {
			delete testMesh;
			delete testShader;
		}

		void update() {
			Input::update();

			static float temp = 0.0;
			temp += Time::getDelta() / 100;
			testShader->setUniformf("maxClamp", (float)std::abs(std::sin(temp)));
		}

		void render() {
			testShader->bind();
			testMesh->draw();
		}
	}
}
