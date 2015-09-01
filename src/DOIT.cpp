/*
 * doit_engine - A 3D Game Engine
 * Copyright (C) 2015 Joshua Brockschmidt
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include <iostream>
#include "DOIT.hpp"

bool wasInit = false;

namespace DOIT {
	InitError::InitError():
		exception(), msg("") {}
	InitError::InitError(const std::string& m):
		exception(), msg(m) {}
        InitError::~InitError() throw() {}
	const char* InitError::what() const throw() {
		return msg.c_str();
	}

	namespace Engine {
		double frameCap;
		bool running;

		void init(unsigned int w, unsigned int h, std::string _title, double _frameCap) {
			Window::open(w, h, _title);
			RenderUtil::init();
			Game::init();
			frameCap = _frameCap;
			running = false;
		}

		void cleanUp() {
			RenderUtil::cleanUp();
			Game::cleanUp();
			Window::close();
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

		void update(double dt) {
			SDL_Event ev;
			while (SDL_PollEvent(&ev)) {
				if (ev.type == SDL_WINDOWEVENT &&
				    ev.window.event == SDL_WINDOWEVENT_CLOSE) {
					if (ev.window.windowID == Window::getID()) {
						stop();
						return;
					}
				}
			}

			Game::update(dt);
		}

		void render() {
		        RenderUtil::clearScreen();
			Game::render();
			Window::render();
		}

		void run() {
			running = true;

			static const double minFrameTime = 1.0 / frameCap;
			double startTime, lastTime, dt, frameTimer;
			lastTime = Time::getTime();
			frameTimer = 0;

			double frameCnt, FPStimer; //DEBUG

			while (true) {
				startTime = Time::getTime();
				dt = startTime - lastTime;
				lastTime = startTime;

				update(dt);
				if (!running) break;

				frameTimer += dt;
				if (frameTimer >= minFrameTime) {
					render();
					frameTimer = 0;
					frameCnt++; //DEBUG
				}

				//DEBUG
				FPStimer += dt;
				if (FPStimer >= 1) {
					std::cout << "FPS: " << frameCnt << std::endl;
					FPStimer = 0;
					frameCnt = 0;
				}
				//EOF DEBUG
			}
		}
	}

	void init(unsigned int w, unsigned int h, std::string title, double frameCap) {
		if (wasInit) return;

		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::string m;
			m.append("Error initializing SDL2: ");
			m.append(SDL_GetError());
			throw InitError(m);
		}

		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

		Engine::init(w, h, title, frameCap);
		Input::init();

		wasInit = true;
	}

	void cleanUp() {
		if (!wasInit) return;

		Engine::cleanUp();
		SDL_Quit();

		wasInit = false;
	}
}
