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

			std::vector<Vertex> verts = {
				Vertex(Vector3f(-0.5f, -0.5f,  0.0f)),
				Vertex(Vector3f( 0.0f,  0.5f,  0.0f)),
				Vertex(Vector3f( 0.5f, -0.5f,  0.0f)),
				Vertex(Vector3f( 0.0f, -0.5f,  0.5f)),
			};

			std::vector<unsigned int> indices = {
				0, 1, 3,
				3, 1, 2,
				2, 1, 0,
				0, 2, 3
			};

		        testMesh->addVertices(verts, indices);
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
			float sinTemp = (float)std::sin(temp);
			float cosTemp = (float)std::cos(temp);
			testTrans1.setRotation((float)M_PI/4, temp, 0);

			testTrans2.setTranslation(cosTemp*0.5f,
						  sinTemp*0.5f,
						  sinTemp );
			testTrans2.setScale(sinTemp, sinTemp, sinTemp);
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
