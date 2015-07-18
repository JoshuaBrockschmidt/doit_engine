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

namespace DOIT {
	class Engine {
	public:
		Window window;

		Engine(unsigned int w, unsigned int h, std::string _title, double _frameCap);
		~Engine();
		void start();
		void stop();
		void setFrameCap(double newFrameCap);
	private:
		double frameCap;
		bool running;

		void update();
		void run();
	};

	void init();
	void cleanUp();
}

#include "time.hpp"

#endif //DOITENGINE_H
