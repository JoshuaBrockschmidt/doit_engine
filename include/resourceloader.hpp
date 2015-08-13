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
