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

		Engine(unsigned int w, unsigned int h, std::string _title);
		~Engine();
		void start();
		void stop();
		void run();
	private:
		bool running;
	};

	void init();
	void cleanUp();
}

#endif //DOITENGINE_H
