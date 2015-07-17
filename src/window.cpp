#include <iostream>
#include "DOIT.hpp"
#include "window.hpp"

namespace DOIT {
	Window::Window(unsigned int w, unsigned int h, std::string _title) {
		win = SDL_CreateWindow(_title.c_str(),
				       SDL_WINDOWPOS_UNDEFINED,
				       SDL_WINDOWPOS_UNDEFINED,
				       w, h,
				       flags );
		if(win == nullptr) {
			throw InitError();
		}

		width = w;
		height = h;
		title = _title;
	}

        Window::~Window() {
		if (win != nullptr) SDL_DestroyWindow(win);
	}

	void Window::render() {
		//TODO: Render everything OpenGL has drawn
		return;
	}

	void Window::setSize(unsigned int w, unsigned int h) {
		SDL_SetWindowSize(win, w, h);
		width = w;
		height = h;
	}

	void Window::setTitle(std::string newTitle) {
		SDL_SetWindowTitle(win, newTitle.c_str());
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
		return SDL_GetWindowID(win);
	}
}
