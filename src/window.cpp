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
			if (SDLwin == NULL) {
				std::string m;
				m += "SDL Error: ";
				m += SDL_GetError();
				throw InitError(m);
			}

			width = w;
			height = h;
			title = _title;
		}

		void close() {
			if (SDLwin != NULL) SDL_DestroyWindow(SDLwin);
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
