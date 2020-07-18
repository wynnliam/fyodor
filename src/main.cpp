// Liam Wynn, 7/11/2020, Fyodor

#include <iostream>
#include <string>

#include "./ray.h"

using namespace std;
using namespace fyodor;

void print_vector(const vector2d& vect) {
	cout << "(" << vect.x << ", " << vect.y << ")" << endl;
}

/*void print_ray(const ray& ray) {
	cout << "Origin: ";
	print_vector(ray.origin);
	cout << "Direction: ";
	print_vector(ray.direction);
	cout << endl;
}*/

void ray_box_test(const ray& ray, const aabb& box, const string& name) {
	cout << name;

	if(ray.collides_with(box))
		cout << " hit!";
	else
		cout << " miss!";

	cout << endl;
}

int main() {
	cout << "Welcome to Fyodor!" << endl;
	ray ray_1(vector2d(2, 1), vector2d(1, 1));
	ray ray_2(vector2d(1, 5), vector2d(1, 1));
	ray ray_3(vector2d(5, 6), vector2d(0, -1));
	aabb box(vector2d(3,3), vector2d(7, 5));

	ray_box_test(ray_1, box, "Ray 1");
	ray_box_test(ray_2, box, "Ray 2");
	ray_box_test(ray_3, box, "Ray 3");

	return 0;
}
