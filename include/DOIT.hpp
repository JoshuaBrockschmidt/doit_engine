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
