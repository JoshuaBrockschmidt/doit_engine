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

#include <array>
#include <iostream>
#include <GL/glew.h>
#include <GL/glu.h>
#include "shader.hpp"

namespace DOIT {
	ShaderError::ShaderError():
		exception(), msg("") {}
	ShaderError::ShaderError(const std::string& m):
		exception(), msg(m) {}
        ShaderError::~ShaderError() throw() {}
	const char* ShaderError::what() const throw() {
		return msg.c_str();
	}

	Shader::Shader() {
		program = glCreateProgram();

		if (program == 0) {
			throw ShaderError("Shader creation failed: "
					"Could not find valid memory location "
					"in constructor");
		}
	}

	Shader::~Shader() {
		glDeleteProgram(program);
		for (std::vector<GLuint>::iterator it = activeShaders.begin();
		     it != activeShaders.end(); ++it)
			glDeleteShader(*it);
	}

	void Shader::addVertexShader(std::string data) {
		addProgram(data, GL_VERTEX_SHADER);
	}

	void Shader::addGeometryShader(std::string data) {
		addProgram(data, GL_GEOMETRY_SHADER);
	}

	void Shader::addFragmentShader(std::string data) {
		addProgram(data, GL_FRAGMENT_SHADER);
	}

	void Shader::compileShader() {
		glLinkProgram(program);

		GLint success;
	        glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (success == GL_FALSE) {
			GLint logLen = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLen);
			GLchar programLog[logLen];
			glGetProgramInfoLog(program, logLen, &logLen, programLog);
			std::string m;
			m += (char *)gluErrorString(glGetError());
			m += ": ";
			m += (char *)programLog;
			throw ShaderError(m);
		}

		glValidateProgram(program);

	        glGetProgramiv(program, GL_VALIDATE_STATUS, &success);
		if (success == GL_FALSE) {
			GLint logLen = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLen);
			GLchar programLog[logLen];
			glGetProgramInfoLog(program, logLen, &logLen, programLog);
			std::string m;
			m += (char *)gluErrorString(glGetError());
			m += ": ";
			m += (char *)programLog;
			throw ShaderError(m);
		}
	}

	void Shader::bind() {
		glUseProgram(program);
	}

	void Shader::addUniform(std::string uName) {
		GLint uniLocation = glGetUniformLocation(program, (const GLchar*)uName.c_str());

		if (uniLocation == -1) {
			std::string m = "Could not find uniform: ";
			m += uName;
			throw ShaderError(m);
		}

		uniforms.insert(std::pair<std::string, GLint>(uName, uniLocation));
	}

	void Shader::setUniformi(std::string uName, int v) {
		glUniform1i(uniforms[uName], v);
	}

	void Shader::setUniformf(std::string uName, float v) {
		glUniform1f(uniforms[uName], v);
	}

	void Shader::setUniform(std::string uName, Vector3f v) {
		glUniform3f(uniforms[uName],
			    v.getX(),
			    v.getY(),
			    v.getZ() );
	}

	void Shader::setUniform(std::string uName, Matrix4f v) {
		std::array<std::array<float, 4>, 4> m = v.getM();
		GLfloat mf[4][4];
		for (int i=0; i<4; i++)
			for (int k=0; k<4; k++)
				mf[i][k] = m[i][k];
		glUniformMatrix4fv(uniforms[uName],
				   1,
				   GL_TRUE, //TODO: Should I transpose?
				   (const GLfloat*) mf );
	}

	void Shader::addProgram(std::string data, GLenum type) {
		GLuint shader = glCreateShader(type);

		if (shader == 0) {
			std::string m;
			m += "Shader creation failed: "
				"Could not find valid memory location when "
				"adding shader: ";
			m += (char *)gluErrorString(glGetError());
			throw ShaderError(m);
		}

		const GLchar* data_c = data.c_str();
		glShaderSource(shader, 1, &data_c, NULL);
		glCompileShader(shader);

		GLint success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE) {
			GLint logLen = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
			GLchar shaderLog[logLen];
			glGetShaderInfoLog(shader, logLen, &logLen, shaderLog);
			std::string m;
			m += (char *)gluErrorString(glGetError());
			m += ": ";
			m += (char *)shaderLog;
			glDeleteShader(shader);
			throw ShaderError(m);
		}

		glAttachShader(program, shader);
		activeShaders.push_back(shader);
	}
}
