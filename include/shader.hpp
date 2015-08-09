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
