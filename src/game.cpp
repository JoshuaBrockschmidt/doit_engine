#define _USE_MATH_DEFINES
#include <cmath>
#include "game.hpp"
#include "mesh.hpp"
#include "resourceloader.hpp"
#include "shader.hpp"
#include "time.hpp"
#include "transform.hpp"
#include "vector3f.hpp"
#include "vertex.hpp"

namespace DOIT {
	namespace Game {
		Mesh* testMesh;
		Shader* testShader;
		Transform testTrans;
		float temp, tau = 2*M_PI;

		void init() {
			testMesh = new Mesh();
			testShader = new Shader();

			Vertex data[] = {
				Vertex(Vector3f(-0.5f, -0.5f,  0.0f)),
				Vertex(Vector3f( 0.0f,  0.5f,  0.0f)),
				Vertex(Vector3f( 0.5f, -0.5f,  0.0f))
			};

		        testMesh->addVertices(data, 3);
			testShader->addVertexShader(ResourceLoader::loadShader("basicVertex.vs"));
			testShader->addFragmentShader(ResourceLoader::loadShader("basicFragment.fs"));
			testShader->compileShader();

			testShader->addUniform("transform");
		}

		void cleanUp() {
			delete testMesh;
			delete testShader;
		}

		void update(double dt) {
			Input::update();

			temp += (float)dt;
			while (temp >= tau) {
				temp -= tau;
			}
			testTrans.setTranslation((float)std::sin(temp)*0.5f,
						 (float)std::cos(temp)*0.5f,
						 0 );
		}

		void render() {
			testShader->bind();

			testShader->setUniform("transform", testTrans.getTransformation());

			testMesh->draw();
		}
	}
}
