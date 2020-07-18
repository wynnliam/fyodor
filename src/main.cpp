// Liam Wynn, 7/11/2020, Fyodor

#include <iostream>

#include "./ray.h"

using namespace std;
using namespace fyodor;

void print_vector(const vector2d& vect) {
	cout << "(" << vect.x << ", " << vect.y << ")" << endl;
}

void print_ray(const ray& ray) {
	cout << "Origin: ";
	print_vector(ray.origin);
	cout << "Direction: ";
	print_vector(ray.direction);
	cout << endl;
}

int main() {
	cout << "Welcome to Fyodor!" << endl;
	ray ray_1(vector2d(2, 1), vector2d(1, 1));
	ray ray_2(vector2d(1, 5), vector2d(1, 1));

	print_ray(ray_1);
	print_ray(ray_2);

	return 0;
}
