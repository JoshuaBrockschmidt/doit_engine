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

		//TODO: Possibly throw an error.
		GLint success;
	        glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (success == GL_FALSE) {
			GLint logLen = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLen);
			GLchar programLog[logLen];
			glGetProgramInfoLog(program, logLen, &logLen, programLog);
			std::cerr << gluErrorString(glGetError()) << ": "
				  << (char *)programLog
				  << std::endl;
			return;
		}

		glValidateProgram(program);

		//TODO: Possibly throw an error.
	        glGetProgramiv(program, GL_VALIDATE_STATUS, &success);
		if (success == GL_FALSE) {
			GLint logLen = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLen);
			GLchar programLog[logLen];
			glGetProgramInfoLog(program, logLen, &logLen, programLog);
			std::cerr << gluErrorString(glGetError()) << ": "
				  << (char *)programLog
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
		glShaderSource(shader, 1, &data_c, NULL);
		glCompileShader(shader);

		//TODO: Possibly throw an error.
		GLint success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE) {
			GLint logLen = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
			GLchar shaderLog[logLen];
			glGetShaderInfoLog(shader, logLen, &logLen, shaderLog);
			std::cerr << gluErrorString(glGetError()) << ": "
				  << (char *)shaderLog
				  << std::endl;
			glDeleteShader(shader);
			return;
		}

		glAttachShader(program, shader);
		activeShaders.push_back(shader);
	}
}
