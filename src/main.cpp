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
	vector2d a(1, 2);
	vector2d b(3, 4);
	vector2d c = a + b;

	print_vector(c);
	return 0;
}
