#ifndef TIME_H
#define TIME_H

#include "DOIT.hpp"

namespace DOIT {
	namespace Time {
		// Second-per-milliseconds
		const Uint32 second = 1000;
		extern double delta;

		Uint32 getTime();
		double getDelta();
		void setDelta(double d);
	}
}

#endif //TIME_H
