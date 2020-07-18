// Liam Wynn, 7/11/2020, Fyodor

#include <iostream>

#include "./vector2d.h"

using namespace std;
using namespace fyodor;

void print_vector(const vector2d& vect) {
	cout << "(" << vect.x << ", " << vect.y << ")" << endl;
}

int main() {
	cout << "Welcome to Fyodor!" << endl;
	vector2d vect(3, 4);
	vector2d vect2(1, 2);
	float scalar = 2.5;

	vect *= scalar;
	print_vector(vect);
	print_vector(vect2 * scalar);
	print_vector(scalar * vect2);

	return 0;
}
