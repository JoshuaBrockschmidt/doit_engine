#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <streambuf>
#include <vector>
#include "resourceloader.hpp"
#include "vertex.hpp"

namespace DOIT {
	ResourceLoaderError::ResourceLoaderError():
		exception(), msg("") {}
	ResourceLoaderError::ResourceLoaderError(const std::string& m):
		exception(), msg(m) {}
        ResourceLoaderError::~ResourceLoaderError() throw() {}
	const char* ResourceLoaderError::what() const throw() {
		return msg.c_str();
	}

	namespace ResourceLoader {
		const std::string shaderDir = std::string("./res/shaders/");

		std::string loadShader(std::string filename) {
			std::ifstream shaderFile(shaderDir + filename);
			if (!shaderFile.is_open()) {
				std::string m;
				m += "Error loading shader: Error opening ";
				m += shaderDir;
				m += filename;
				m += ": ";
				m += std::strerror(errno);
				throw ResourceLoaderError(m);
			}

			std::string content((std::istreambuf_iterator<char>(shaderFile)),
					     std::istreambuf_iterator<char>());

			shaderFile.close();

			return content;
		}

		Mesh* loadMesh(std::string filename) {
			const std::string meshDir = std::string("./res/models/");

			size_t splitPos = filename.find('.');
			if (splitPos == std::string::npos ||
			    filename.substr(splitPos + 1) != "obj") {
				std::string m;
				m += "Error loading mesh: "
					"Incorrect file extension; "
					"Should be .obj";
				throw ResourceLoaderError(m);
			}

			std::ifstream meshFile(meshDir + filename);
			if (!meshFile.is_open()) {
				std::string m;
				m += "Error loading mesh: Error opening ";
				m += meshDir;
				m += filename;
				m += ": ";
				m += std::strerror(errno);
				throw ResourceLoaderError(m);
			}

			std::vector<Vertex> verts;
			std::vector<unsigned int> faces;

			std::string line;
			std::istringstream iss;
			while (std::getline(meshFile, line)) {
				iss.exceptions(std::ios::badbit);
				iss.str(line);
				std::vector<std::string> tokens {
					std::istream_iterator<std::string>{iss},
				        std::istream_iterator<std::string>{}
				};
				iss.clear();

				iss.exceptions(std::ios::failbit | std::ios::badbit);
				if (tokens[0] == "v") {
					if (tokens.size() != 4) {
						std::string m =
							"Error loading mesh: "
							"Bad vertex";
						throw ResourceLoaderError(m);
					}

					float vCoords[3];
					try {
						for (int i=0; i<3; i++) {
							float f;
							iss.str(tokens[i+1]);
							iss >> f;
							iss.clear();
							vCoords[i] = f;
						}

					} catch (const std::ifstream::failure& e) {
						std::string m;
						m += "Error loading mesh: "
							"Bad vertex: ";
						m += e.what();
						throw ResourceLoaderError(m);
					}
					verts.push_back(Vertex(vCoords[0],
							       vCoords[1],
							       vCoords[2]) );

				} else if (tokens[0] == "f") {
					if (tokens.size() != 4) {
						std::string m =
							"Error loading mesh: "
							"Bad face";
						throw ResourceLoaderError(m);
					}

					try {
						for (int i=1; i<4; i++) {
							unsigned int ui;
							iss.str(tokens[i]);
							iss >> ui;
							iss.clear();
							faces.push_back(ui-1);
						}
					} catch (const std::ifstream::failure& e) {
						std::string m;
						m += "Error loading mesh: "
							"Bad face: ";
						m += e.what();
						throw ResourceLoaderError(m);
					}
				}
			}

			Mesh* newMesh = new Mesh();
			newMesh->addVertices(verts, faces);

			return newMesh;
		}
	}
}
