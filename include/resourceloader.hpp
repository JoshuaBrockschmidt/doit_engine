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

#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <string>
#include "mesh.hpp"

namespace DOIT {
	class ResourceLoaderError: public std::exception {
	public:
	        ResourceLoaderError();
	        ResourceLoaderError(const std::string& m);
		virtual ~ResourceLoaderError() throw();
		virtual const char* what() const throw();
	private:
		std::string msg;
	};

	namespace ResourceLoader {
		extern const std::string shaderDir;

		/* Loads a GLSL shader from a file. If specified file does not
		 * exist or cannot be opened, a ResourceLoaderError is thrown.
		 *
		 * @param filename Path of file relative to res/shaders/
		 * @return Shader code.
		 */
		std::string loadShader(std::string filename);

		/* Loads a mesh from a .obj file. If specified file does not
		 * exist, cannot be opened, has the wrong extension, or is
		 * formatted incorrectly a ResourceLoaderError is thrown.
		 *
		 * WARNING: .obj objects must be exported without normals in
		 *          the meantime. (TODO: Add normals support.)
		 *
		 * @param filename Path of file relative to the res/models/
		 * @return A mesh, as specified by the .obj file.
		 */
		Mesh* loadMesh(std::string filename);
	}
}

#endif //RESOURCELOADER_H
