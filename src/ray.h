// Liam Wynn, 7/16/2020, Fyodor

#ifndef RAY
#define RAY

#include "./aabb.h"

namespace fyodor {
	class ray {
		public:
			ray() { }
			ray(vector2d new_or, vector2d new_dir);

			vector2d at(const float t) const;

			bool collides_with(const aabb& box) const;

			vector2d origin;
			vector2d direction;
			// A precalculated value so we can do collides_with without
			// any division.
			vector2d direction_inverse;
	};
}
#endif
