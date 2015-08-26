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

#ifndef SHADER_H
#define SHADER_H

#include <map>
#include <vector>
#include <GL/gl.h>
#include "matrix4f.hpp"
#include "vector3f.hpp"

namespace DOIT {
	class ShaderError: public std::exception {
	public:
		ShaderError();
		ShaderError(const std::string& m);
		virtual ~ShaderError() throw();
		virtual const char* what() const throw();
	private:
		std::string msg;
	};

	class Shader {
	public:
		Shader();
		~Shader();
		void addVertexShader(std::string data);
		void addGeometryShader(std::string data);
		void addFragmentShader(std::string data);
		void compileShader();
		void bind();
		void addUniform(std::string uName);
		void setUniformi(std::string uName, int v);
		void setUniformf(std::string uName, float v);
		void setUniform(std::string uName, Vector3f v);
		void setUniform(std::string uName, Matrix4f v);
	private:
		GLuint program;
		std::vector<GLuint> activeShaders;
		std::map <std::string, GLint> uniforms;

		void addProgram(std::string data, GLenum type);
	};
}

#endif //SHADER_H
