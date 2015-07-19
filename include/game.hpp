#ifndef GAME_H
#define GAME_H

#include "input.hpp"

namespace DOIT {
	class Game {
	public:
		Input input;

		Game();
		~Game();
		void update();
		void render();
	};
}

#endif //GAME_H
