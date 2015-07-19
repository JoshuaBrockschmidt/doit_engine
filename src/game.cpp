#include "game.hpp"

namespace DOIT {
	Game::Game():
		input() {}

	Game::~Game() {}

	void Game::update() {
		input.update();
	}

	void Game::render() {}
}
