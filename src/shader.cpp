#include <iostream>
#include <GL/glew.h>
#include <GL/glu.h>
#include "shader.hpp"

namespace DOIT {
	Shader::Shader() {
		program = glCreateProgram();

		if (program == 0) {
			//TODO: Possibly throw an error.
			std::cerr << "Shader creation failed: "
				  << "Could not find valid memory location in constructor"
				  << std::endl;
			return;
		}
	}

	Shader::~Shader() {}

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

		//TODO: Possibly throw an error.
		GLint params;
		glGetShaderiv(program, GL_LINK_STATUS, &params);
		if (params == 0) {
			GLchar* shaderLog;
			glGetShaderInfoLog(program, 1024, NULL, shaderLog);
			std::cerr << gluErrorString(glGetError()) << ": "
				  << (char *)shaderLog
				  << std::endl;
			return;
		}

		glValidateProgram(program);

		//TODO: Possibly throw an error.
		glGetShaderiv(program, GL_VALIDATE_STATUS, &params);
		if (params == 0) {
			GLchar* shaderLog;
			glGetShaderInfoLog(program, 1024, NULL, shaderLog);
			std::cerr << gluErrorString(glGetError()) << ": "
				  << (char *)shaderLog
				  << std::endl;
			return;
		}
	}

	void Shader::bind() {
		glUseProgram(program);
	}

	void Shader::addProgram(std::string data, GLenum type) {
		GLuint shader = glCreateShader(type);

		//TODO: Possibly throw an error.
		if (shader == 0) {
			std::cerr << "Shader creation failed: "
				  << "Could not find valid memory location when adding shader: "
				  << gluErrorString(glGetError())
				  << std::endl;
			return;
		}

		const GLchar* data_c = data.c_str();
		const GLint len = data.length();
		glShaderSource(shader, 1, &data_c, &len);
		glCompileShader(shader);

		//TODO: Possibly throw an error.
		GLint params;
		glGetShaderiv(program, GL_COMPILE_STATUS, &params);
		if (params == 0) {
			GLchar* shaderLog;
			glGetShaderInfoLog(program, 1024, NULL, shaderLog);
			std::cerr << gluErrorString(glGetError()) << ": "
				  << (char *)shaderLog
				  << std::endl;
			return;
		}

		glAttachShader(shader, program);
	}
}
