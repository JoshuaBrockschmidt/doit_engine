/*
 * doit_engine - A 3D Game Engine
 * Copyright (C) 2015 Joshua Brockschmidt
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

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
#include "window.hpp"

namespace DOIT {
	namespace Game {
		Mesh *testMesh;
		Shader* testShader;
		Transform testTrans;
		float temp, tau = 2*M_PI;

		void init() {
			testMesh = ResourceLoader::loadMesh("cube.obj");
			testShader = new Shader();

			testShader->addVertexShader(ResourceLoader::loadShader("basicVertex.vs"));
			testShader->addFragmentShader(ResourceLoader::loadShader("basicFragment.fs"));
			testShader->compileShader();

			testShader->addUniform("transform");

			testTrans.setProjection(90.0f,
						Window::getWidth(),
						Window::getHeight(),
						0.1f,
						1000.0f );
			testTrans.setTranslation(0.0f, 0.0f, 4.0f);
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
			testTrans.setRotation(-temp, -temp, -temp);
		}

		void render() {
			testShader->bind();

			testShader->setUniform("transform", testTrans.getProjectedTransformation());
			testMesh->draw();
		}
	}
}
