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

#ifndef RENDERUTIL_H
#define RENDERUTIL_H

#include <string>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

namespace DOIT {
	namespace RenderUtil {
		extern bool GLEW_wasInit;

		/* Initialize some OpenGL functionality.
		 * That's as specific as I can be. You're welcome.
		 */
		void init();

		/* Clean up.
		 */
		void cleanUp();

		/* Clear everything on the screen.
		 */
		void clearScreen();

		/* Returns the OpenGL version as a string.
		 */
		std::string getOpenGLVersion();
	}
}

#endif //RENDERUTIL_H
