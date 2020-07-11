// Liam Wynn, 7/11/2020, Fyodor

/*
	AABB stands for "Axis Alligned Bounding Box".
	Since that's a long name for a class, we just say
	aabb.

	An aabb has two vectors: one to describe the top left
	corner and another to describe to bottom right. However,
	do note that this class will not make any effort to verify
	that these are correct!
*/

#ifndef AABB
#define AABB

#include "./vector2d.h"

namespace fyodor {
	class aabb {
		public:
			vector2d top_left, bottom_right;

			aabb() { }
			aabb(const vector2d& tl, const vector2d& br) : top_left(tl), bottom_right(br) { }
	};
}

#endif
