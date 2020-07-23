// Liam Wynn, 7/11/2020, Fyodor

#include "./aabb.h"

using namespace fyodor;

/*
	Solution based on:
	https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection
*/
bool aabb::collides_with(const aabb& other) const {
	return top_left.x < other.bottom_right.x &&
		   bottom_right.x > other.top_left.x &&
		   top_left.y < other.bottom_right.y &&
		   bottom_right.y > other.top_left.y;
}
