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

#include "window.hpp"
#include "input.hpp"
#include "game.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "matrix4.hpp"
#include "quaternion.hpp"
#include "renderutil.hpp"

namespace DOIT {
	namespace Engine {
		extern Window* window;
		extern double frameCap;
		extern bool running;

	        void init(unsigned int w, unsigned int h, std::string _title, double _frameCap);
		void cleanUp();
		void update();
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
