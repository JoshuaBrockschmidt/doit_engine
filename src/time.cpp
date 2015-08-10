#include "time.hpp"

namespace DOIT {
	namespace Time {
		// Second-per-milliseconds
		const double second = 1000;

		double delta = 0;

		double getTime() {
			return (double)SDL_GetTicks() / second;
		}
	}
}
