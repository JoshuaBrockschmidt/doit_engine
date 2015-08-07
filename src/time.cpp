#include "time.hpp"

namespace DOIT {
	namespace Time {
		double delta = 0;

		Uint32 getTime() {
			//TODO: Consider using nano seconds instead.
			return SDL_GetTicks();
		}

		double getDelta() {
			return delta;
		}

		void setDelta(double d) {
			delta = d;
		}
	}
}
