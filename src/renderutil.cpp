#include <iostream>
#include <GL/glu.h>
#include "DOIT.hpp"
#include "renderutil.hpp"

namespace DOIT {
	namespace RenderUtil {
	        SDL_GLContext glContext;

		void init() {
			SDL_Window* win = SDL_GetWindowFromID(Engine::window->getID());
			glContext = SDL_GL_CreateContext(win);
			if (glContext == NULL) {
				std::string m;
				m.append("Error associating window with OpenGL: SDL Error: ");
				m.append(SDL_GetError());
				throw InitError(m);
			}

			glClearColor(0.0f, 0.0f, 0.0f, 0.2f);
			glFrontFace(GL_CW);
			glCullFace(GL_BACK);
			glEnable(GL_CULL_FACE);
			glEnable(GL_DEPTH_TEST);

			//TODO: Depth clamp for later.

			glEnable(GL_FRAMEBUFFER_SRGB);

			if(SDL_GL_SetSwapInterval(1) < 0) {
				std::cerr << "Warning: Unable to set VSync! "
					  << "SDL Error: "
					  << SDL_GetError() << std::endl;
			}

			GLenum error = glGetError();
			if (error != GL_NO_ERROR) {
				std::string m;
				m.append("Error initializing OpenGL: OpenGL Error: ");
				m.append(reinterpret_cast<const char*>(gluErrorString(error)));
				throw InitError(m);
			}
		}

		void cleanUp() {
			SDL_GL_DeleteContext(glContext);
		}

		void clearScreen() {
			//TODO: Stencil buffer.
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}
}
