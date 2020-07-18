// Liam Wynn, 7/11/2020, Fyodor

#include "./vector2d.h"

using namespace fyodor;

vector2d& vector2d::operator+= (const vector2d& to_add) {
	x += to_add.x;
	y += to_add.y;

	return *this;
}
