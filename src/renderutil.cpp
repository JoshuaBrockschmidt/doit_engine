#include <iostream>
#include <GL/glew.h>
#include <GL/glu.h>
#include "DOIT.hpp"
#include "renderutil.hpp"

namespace DOIT {
	namespace RenderUtil {
		bool GLEW_wasInit = false;

	        SDL_GLContext glContext;

		void init() {
			SDL_Window* win = SDL_GetWindowFromID(Window::getID());
			glContext = SDL_GL_CreateContext(win);
			if (glContext == NULL) {
				std::string m;
				m += "SDL Error: ";
				m += SDL_GetError();
				throw InitError(m);
			}

			glewExperimental = GL_TRUE;
			GLenum glewErr = glewInit();
			if (glewErr != GLEW_OK) {
				std::string m;
				m.append("Error initializing OpenGL GLEW extension: ");
				m.append((const char*)glewGetErrorString(glewErr));
				throw InitError(m);
			} else {
				/* GLEW does not play nice with OpenGL 4.4.
				 * GLEW thinks OpenGL 4.4 is "pretentious" and
				 * "entitled". GLEW likes to throw an invalid
				 * enumerant error the next time glGetError is
				 * called after GLEW's initialization.
				 * glGetError must be envoked to discard this
				 * faulty error. GLEW makes my code look sloppy.
				 * We do not like GLEW. We tolerate GLEW.
				 */
				GLenum junk = glGetError();
			}
			GLEW_wasInit = true;

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glFrontFace(GL_CCW); //CW or CCW?
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

		std::string getOpenGLVersion() {
			return std::string((const char*)glGetString(GL_VERSION));
		}
	}
}
