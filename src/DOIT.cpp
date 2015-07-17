#include "DOIT.hpp"

bool wasInit = false;

namespace DOIT {
	InitError::InitError():
		exception(), msg(SDL_GetError()) {}
	InitError::InitError(const std::string& m):
		exception(), msg(m) {}
        InitError::~InitError() throw() {}
	const char* InitError::what() const throw() {
		return msg.c_str();
	}

	Engine::Engine(unsigned int w, unsigned int h, std::string _title):
		window(w, h, _title) {
		running = false;
	}

	Engine::~Engine() {}

	void Engine::start() {
		if (running) return;

		running = true;
		run();
	}

	void Engine::stop() {
		running = false;
	}

	void Engine::run() {
		SDL_Event ev;
		while(running) {
			while (SDL_PollEvent(&ev)) {
				if (ev.type == SDL_WINDOWEVENT &&
				    ev.window.event == SDL_WINDOWEVENT_CLOSE)
					if (ev.window.windowID == window.getID())
						running = false;
			}
			window.render();
		}
	}

	void init() {
		if (wasInit) return;

		if (!SDL_WasInit(SDL_INIT_VIDEO)) {
			if(SDL_Init(SDL_INIT_VIDEO) != 0)
				throw InitError();

			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		}

		wasInit = true;
	}

	void cleanUp() {
		if (!wasInit) return;

		SDL_Quit();

		wasInit = false;
	}
}
