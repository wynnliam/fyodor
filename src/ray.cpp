// Liam Wynn, 7/16/2020, Fyodor

#include "ray.h"

using namespace fyodor;

ray::ray(vector2d new_or, vector2d new_dir) : origin(new_or), direction(new_dir) {
	direction.normalize();
}
