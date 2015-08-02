#include <iostream>
#include "DOIT.hpp"
#include "window.hpp"

namespace DOIT {
	namespace Window {
		SDL_Window* SDLwin;
		unsigned int width;
		unsigned int height;
		std::string title;

		void open(unsigned int w, unsigned int h, std::string _title) {
			SDLwin = SDL_CreateWindow(_title.c_str(),
						  SDL_WINDOWPOS_UNDEFINED,
						  SDL_WINDOWPOS_UNDEFINED,
						  w, h,
						  flags );
			if (SDLwin == nullptr) {
				throw InitError(SDL_GetError());
			}

			width = w;
			height = h;
			title = _title;
		}

		void close() {
			if (SDLwin != nullptr) SDL_DestroyWindow(SDLwin);
		}

		void render() {
			SDL_GL_SwapWindow(SDLwin);
		}

		void setSize(unsigned int w, unsigned int h) {
			SDL_SetWindowSize(SDLwin, w, h);
			width = w;
			height = h;
		}

		void setTitle(std::string newTitle) {
			SDL_SetWindowTitle(SDLwin, newTitle.c_str());
		}

		unsigned int getWidth() {
			return width;
		}

		unsigned int getHeight() {
			return height;
		}

		std::string getTitle() {
			return title;
		}

		Uint32 getID() {
			return SDL_GetWindowID(SDLwin);
		}
	}
}
