// Liam Wynn, 7/16/2020, Fyodor

#include "ray.h"
#include <algorithm>

using namespace fyodor;

ray::ray(vector2d new_or, vector2d new_dir) : origin(new_or), direction(new_dir) {
	direction.normalize();
}

vector2d ray::at(const float t) const {
	// t must be > 0!
	return origin + ((t < 0.0f ? 0.0f : t) * direction);
}

// TODO: Case of dir.x or dir.y being 0!!!!
bool ray::collides_with(const aabb& box) const {
	float txmin = (box.top_left.x - origin.x) / direction.x;
	float tymin = (box.bottom_right.y - origin.y) / direction.y;
	float txmax = (box.bottom_right.x - origin.x) / direction.x;
	float tymax = (box.top_left.y - origin.y) / direction.y;

	float txenter = std::min(txmin, txmax);
	float txexit = std::max(txmin, txmax);
	float tyenter = std::min(tymin, tymax);
	float tyexit = std::max(tymin, tymax);

	float tenter = std::max(txenter, tyenter);
	float texit = std::min(txexit, tyexit);

	return tenter <= texit;
}
