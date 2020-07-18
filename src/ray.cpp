// Liam Wynn, 7/16/2020, Fyodor

#include "ray.h"

using namespace fyodor;

ray::ray(vector2d new_or, vector2d new_dir) : origin(new_or), direction(new_dir) {
	direction.normalize();
}

vector2d ray::at(const float t) const {
	// t must be > 0!
	return origin + ((t < 0.0f ? 0.0f : t) * direction);
}
