#ifndef TIME_H
#define TIME_H

#include "DOIT.hpp"

namespace DOIT {
	namespace Time {
		extern double delta;

		/* Returns the current time.
		 *
		 * @return Time in seconds.
		 */
		double getTime();
	}
}

#endif //TIME_H
