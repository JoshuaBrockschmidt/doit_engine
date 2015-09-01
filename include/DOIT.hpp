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

#ifndef DOITENGINE_H
#define DOITENGINE_H

#include <exception>
#include <string>
#include <SDL2/SDL.h>

namespace DOIT {
	class InitError: public std::exception {
	public: 
		InitError();
		InitError(const std::string& m);
		virtual ~InitError() throw();
		virtual const char* what() const throw();
	private:
		std::string msg;
	};
}

#include "game.hpp"
#include "input.hpp"
#include "matrix4f.hpp"
#include "mesh.hpp"
#include "quaternion.hpp"
#include "renderutil.hpp"
#include "resourceloader.hpp"
#include "shader.hpp"
#include "transform.hpp"
#include "vector2f.hpp"
#include "vector3f.hpp"
#include "vertex.hpp"
#include "window.hpp"

namespace DOIT {
	namespace Engine {
		extern double frameCap;
		extern bool running;

	        void init(unsigned int w, unsigned int h, std::string _title, double _frameCap);
		void cleanUp();
		void update(double dt);
		void render();
		void run();
		void start();
		void stop();
		void setFrameCap(double newFrameCap);
	};

	void init(unsigned int w, unsigned int h, std::string title, double frameCap);
	void cleanUp();
}

#include "time.hpp"

#endif //DOITENGINE_H
