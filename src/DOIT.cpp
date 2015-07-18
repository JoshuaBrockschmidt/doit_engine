#include <iostream>
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

	Engine::Engine(unsigned int w, unsigned int h, std::string _title, double _frameCap):
		window(w, h, _title), game() {
		frameCap = _frameCap;
		running = false;
	}

	Engine::~Engine() {}

	void Engine::start() {
		if (running) return;
		run();
	}

	void Engine::stop() {
		running = false;
	}

	void Engine::setFrameCap(double newFrameCap) {
		//TODO: Possibly throw an error.
		if (newFrameCap <= 0)
			return;

		frameCap = newFrameCap;
	}

	void Engine::update() {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			if (ev.type == SDL_WINDOWEVENT &&
			    ev.window.event == SDL_WINDOWEVENT_CLOSE)
				if (ev.window.windowID == window.getID()) {
					stop();
					return;
				}
		}

		game.input();
		game.update();
	}

	void Engine::render() {
		window.render();
		game.render();
	}

	void Engine::run() {
		running = true;

		int frames = 0;
		Uint32 frameCnt = 0;

		const double frameTime = 1.0 / frameCap;
		Uint32 startTime, passedTime, lastTime;
		double unprocessedTime = 0;
		lastTime = Time::getTime();

		while(running) {
			startTime = Time::getTime();
			passedTime = startTime - lastTime;
			lastTime = startTime;
			unprocessedTime += passedTime / (double)Time::second;
			frameCnt += passedTime;

			while (unprocessedTime > frameTime) {
				unprocessedTime -= frameTime;

				update();

				if (frameCnt >= Time::second) {
					std::cout << "FPS: " << frames << std::endl;
					frames = 0;
					frameCnt = 0;
				}

				render();
				frames++;
			}
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
