#include <iostream>
#include <string>
#include "DOIT.hpp"

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;
const std::string TITLE = "Test Window";
const double FRAME_CAP = 5000.0;

int main() {
	try {
	        DOIT::init(WIDTH, HEIGHT, TITLE, FRAME_CAP);
	} catch (const DOIT::InitError& e) {
		std::cerr << "Could not initialize: "
			  << e.what() << std::endl;
		return 1;
	} catch (const std::bad_alloc& e) {
		std::cerr << "Could not allocate space for engine: "
			  << e.what() << std::endl;
		return 1;
	}

	DOIT::Engine::start();

	DOIT::cleanUp();

	return 0;
}
