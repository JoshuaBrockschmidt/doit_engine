#ifndef GAME_H
#define GAME_H

#include "input.hpp"

namespace DOIT {
	namespace Game {
		void init();
		void cleanUp();
		void update(double dt);
		void render();
	}
}

#endif //GAME_H
