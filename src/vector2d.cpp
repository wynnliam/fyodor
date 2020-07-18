// Liam Wynn, 7/11/2020, Fyodor

#include "./vector2d.h"

#include <utility>
#include <cmath>

using namespace fyodor;

vector2d& vector2d::operator+= (const vector2d& to_add) {
	x += to_add.x;
	y += to_add.y;

	return *this;
}

vector2d operator+ (const vector2d& a, const vector2d& b) {
	return vector2d(a.x + b.x, a.y + b.y);
}

vector2d& vector2d::operator*= (const float& scalar) {
	x *= scalar;
	y *= scalar;

	return *this;
}

vector2d operator* (const float& scalar, const vector2d& vect) {
	return vector2d(vect.x * scalar, vect.y * scalar);
}

vector2d operator* (const vector2d& vect, const float& scalar) {
	return vector2d(vect.x * scalar, vect.y * scalar);
}

float vector2d:: magnitude() const {
	return (float)sqrt((x * x) + (y * y));
}
