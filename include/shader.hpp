#ifndef SHADER_H
#define SHADER_H

#include <vector>
#include <GL/gl.h>

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
	private:
		GLuint program;
		std::vector<GLuint> activeShaders;

		void addProgram(std::string data, GLenum type);
	};
}

#endif //SHADER_H
