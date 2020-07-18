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

		private:
			vector2d origin;
			vector2d direction;
	};
}
#endif
