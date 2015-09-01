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

#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL2/SDL.h>

namespace DOIT {
	namespace Window {
		const Uint32 flags = SDL_WINDOW_OPENGL;

		/**
		   Initialize window.
		 */
		void open(unsigned int w, unsigned int h, std::string _title);

		/**
		   Cleanup and close.
		*/
		void close();

		/**
		   Render everything OpenGL has drawn.
		*/
		void render();

		/**
		   Sets the size of a window.

		   @param w New width of window.
		   @param h New height of window.
		*/
		void setSize(unsigned int w, unsigned int h);

		/**
		   Sets the title of a window.

		   @param newTitle New title of window.
		*/
		void setTitle(std::string newTitle);

		/**
		   Returns the width of a window
		*/
		unsigned int getWidth();

		/**
		   Returns the width of a window
		*/
		unsigned int getHeight();

		/**
		   Returns the title of a window
		*/
		std::string getTitle();

		/**
		   Returns SDL window ID.
		*/
		Uint32 getID();
	};
}

#endif
