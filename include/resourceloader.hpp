#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <string>

namespace DOIT {
	namespace ResourceLoader {
		extern const std::string shaderDir;

		/* Loads a shader from a filename relative to ./res/shaders/
		 * If specified filename does no exist, an empty string is
		 * returned.
		 */
		std::string loadShader(std::string filename);
	}
}

#endif //RESOURCELOADER_H
