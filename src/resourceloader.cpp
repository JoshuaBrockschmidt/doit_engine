#include <cerrno>
#include <cstring>
#include <iostream>
#include <fstream>
#include "resourceloader.hpp"

namespace DOIT {
	namespace ResourceLoader {
		std::string loadShader(std::string filename) {
			std::ifstream shaderFile(shaderDir + filename);
			if (shaderFile.fail()) {
				std::cerr << "Could not load shader: "
					  << "Error opening "
					  << shaderDir << filename
					  << ": " << std::strerror(errno)
					  << std::endl;
				//TODO: Possibly throw an exception.
				return std::string("");
			}

			std::string content((std::istreambuf_iterator<char>(shaderFile)),
					    (std::istreambuf_iterator<char>()) );
			shaderFile.close();

			return content;
		}
	}
}
