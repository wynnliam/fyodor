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
	vector2d copy_vect;

	copy_vect = vect.get_normalized();

	print_vector(vect);
	cout << "magnitude: " << vect.magnitude() << endl;
	print_vector(copy_vect);

	return 0;
}
