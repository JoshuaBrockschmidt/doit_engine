#include <iostream>
#include "DOIT.hpp"
#include "window.hpp"

namespace DOIT {
	Window::Window(unsigned int w, unsigned int h, std::string _title) {
		SDLwin = SDL_CreateWindow(_title.c_str(),
				       SDL_WINDOWPOS_UNDEFINED,
				       SDL_WINDOWPOS_UNDEFINED,
				       w, h,
				       flags );
		if (SDLwin == nullptr) {
			throw InitError(SDL_GetError());
		}

		//DEBUG
		std::cout << "Window ID: " << SDL_GetWindowID(SDLwin) << std::endl;
		//EOF DEBUG

		width = w;
		height = h;
		title = _title;
	}

        Window::~Window() {
		if (SDLwin != nullptr) SDL_DestroyWindow(SDLwin);
	}

	void Window::render() {
		SDL_GL_SwapWindow(SDLwin);
	}

	void Window::setSize(unsigned int w, unsigned int h) {
		SDL_SetWindowSize(SDLwin, w, h);
		width = w;
		height = h;
	}

	void Window::setTitle(std::string newTitle) {
		SDL_SetWindowTitle(SDLwin, newTitle.c_str());
	}

	unsigned int Window::getWidth() {
		return width;
	}

	unsigned int Window::getHeight() {
		return height;
	}

	std::string Window::getTitle() {
		return title;
	}

	Uint32 Window::getID() {
		return SDL_GetWindowID(SDLwin);
	}
}
