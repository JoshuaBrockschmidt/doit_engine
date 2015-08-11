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
		Transform testTrans1, testTrans2;
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
			float rot = temp/2 - (float)M_PI;
			testTrans1.setTranslation((float)std::sin(temp)*0.5f,
						  (float)std::cos(temp)*0.5f,
						  0 );
			testTrans1.setRotation(std::cos(temp), std::sin(temp), std::cos(temp));
			testTrans2.setTranslation((float)std::sin(-temp)*0.5f,
						  (float)std::sin(-temp)*0.5f,
						  0 );

			testTrans2.setRotation(std::sin(temp), std::cos(temp), std::sin(temp));
		}

		void render() {
			testShader->bind();

			testShader->setUniform("transform", testTrans1.getTransformation());
			testMesh->draw();

			testShader->setUniform("transform", testTrans2.getTransformation());
			testMesh->draw();
		}
	}
}
