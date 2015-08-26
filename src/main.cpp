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

#include <iostream>
#include <string>
#include "DOIT.hpp"

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;
const std::string TITLE = "Test Window";
const double FRAME_CAP = 100.0;

int main() {
	try {
	        DOIT::init(WIDTH, HEIGHT, TITLE, FRAME_CAP);
	} catch (const DOIT::InitError& e) {
		std::cerr << "Could not initialize: "
			  << e.what() << std::endl;
		return 1;
	} catch (const std::bad_alloc& e) {
		std::cerr << "Could not allocate space for engine: "
			  << e.what() << std::endl;
		return 1;
	}
	std::cout << "OpenGL Version: " << DOIT::RenderUtil::getOpenGLVersion() << std::endl;

	DOIT::Engine::start();

	DOIT::cleanUp();

	return 0;
}
