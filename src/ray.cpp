// Liam Wynn, 7/16/2020, Fyodor

#include "ray.h"
#include <algorithm>
#include <limits>

using namespace fyodor;

ray::ray(vector2d new_or, vector2d new_dir) : origin(new_or), direction(new_dir) {
	direction.normalize();

	// Setting these to infinity will ensure that the branchless ray-box collision handles
	// cases of straight-line rays correctly.
	if(direction.x != 0)
		direction_inverse.x = 1 / direction.x;
	else
		direction_inverse.x = std::numeric_limits<float>::infinity();

	if(direction.y != 0)
		direction_inverse.y = 1 / direction.y;
	else
		direction_inverse.y = std::numeric_limits<float>::infinity();
}

vector2d ray::at(const float t) const {
	// t must be > 0!
	return origin + ((t < 0.0f ? 0.0f : t) * direction);
}

// TODO: Case of dir.x or dir.y being 0!!!!
bool ray::collides_with(const aabb& box) const {
	const float POS_INF = std::numeric_limits<float>::infinity();
	const float NEG_INF = -std::numeric_limits<float>::infinity();

	float txmin = (box.top_left.x - origin.x) * direction_inverse.x;
	float tymin = (box.bottom_right.y - origin.y) * direction_inverse.y;
	float txmax = (box.bottom_right.x - origin.x) * direction_inverse.x;
	float tymax = (box.top_left.y - origin.y) * direction_inverse.y;

	// Doing it this way will squash any nan propagation (which occurs
	// when we try to multiply 0 with +/- inf.
	float txenter = std::min(txmin, std::max(txmax, NEG_INF));
	float txexit = std::max(txmin, std::min(txmax, POS_INF));
	float tyenter = std::min(tymin, std::max(tymax, NEG_INF));
	float tyexit = std::max(tymin, std::min(tymax, POS_INF));

	float tenter = std::max(txenter, std::min(tyenter, POS_INF));
	float texit = std::min(txexit, std::max(tyexit, NEG_INF));

	return tenter <= texit;
}
