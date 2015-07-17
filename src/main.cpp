#include <iostream>
#include <string>
#include "DOIT.hpp"

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;
const std::string TITLE = "Test Window";
DOIT::Engine *engine;

int main() {
	try {
		DOIT::init();
		engine = new DOIT::Engine(WIDTH, HEIGHT, TITLE);
	} catch (const DOIT::InitError& e) {
		std::cerr << "Could not initialize: "
			  << e.what() << std::endl;
		return 1;
	} catch (const std::bad_alloc& e) {
		std::cerr << "Could not allocate space for engine: "
			  << e.what() << std::endl;
		return 1;
	}

	engine->start();

	delete engine;
	DOIT::cleanUp();

	return 0;
}
