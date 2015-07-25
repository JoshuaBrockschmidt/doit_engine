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

	namespace Engine {
		Window* window;
		double frameCap;
		bool running;

		void init(unsigned int w, unsigned int h, std::string _title, double _frameCap) {
			window = new Window(w, h, _title);
			frameCap = _frameCap;
			running = false;
		}

		void cleanUp() {
			delete window;
		}

		void start() {
			if (running) return;
			run();
		}

		void stop() {
			running = false;
		}

		void setFrameCap(double newFrameCap) {
			//TODO: Possibly throw an error.
			if (newFrameCap <= 0)
				return;

			frameCap = newFrameCap;
		}

		void update() {
			SDL_Event ev;
			while (SDL_PollEvent(&ev)) {
				if (ev.type == SDL_WINDOWEVENT &&
				    ev.window.event == SDL_WINDOWEVENT_CLOSE)
					if (ev.window.windowID == window->getID()) {
						stop();
						return;
					}
			}

			Game::update();
		}

		void render() {
			window->render();
			Game::render();
		}

		void run() {
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
						//DEBUG
						std::cout << "FPS: " << frames << std::endl;
						//EOF DEBUG
						frames = 0;
						frameCnt = 0;
					}

					render();
					frames++;
				}
			}
		}
	}

	void init(unsigned int w, unsigned int h, std::string title, double frameCap) {
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

		Engine::init(w, h, title, frameCap);
		Input::init();

		wasInit = true;
	}

	void cleanUp() {
		if (!wasInit) return;

		SDL_Quit();

		Engine::cleanUp();

		wasInit = false;
	}
}
