#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include "resourceloader.hpp"

namespace DOIT {
	namespace ResourceLoader {
		const std::string shaderDir = std::string("./res/shaders/");

		std::string loadShader(std::string filename) {
			std::ifstream shaderFile(shaderDir + filename);
			if (!shaderFile.is_open()) {
				std::cerr << "Could not load shader: "
					  << "Error opening "
					  << shaderDir << filename
					  << ": " << std::strerror(errno)
					  << std::endl;
				//TODO: Possibly throw an exception.
				return std::string("");
			}

			std::string content, line;
			while (std::getline(shaderFile, line)) {
				content += line + '\n';
			}

			shaderFile.close();

			return content;
		}
	}
}
