// Liam Wynn, 7/11/2020, Fyodor

#include <iostream>
#include <string>

//#include "./ray.h"
#include "./render.h"
#include "./shader_program.h"
#include "./texture.h"

using namespace std;
using namespace fyodor;

/*void print_vector(const vector2d& vect) {
	cout << "(" << vect.x << ", " << vect.y << ")" << endl;
}*/

/*void print_ray(const ray& ray) {
	cout << "Origin: ";
	print_vector(ray.origin);
	cout << "Direction: ";
	print_vector(ray.direction);
	cout << endl;
}*/

/*void ray_box_test(const ray& ray, const aabb& box, const string& name) {
	cout << name;

	if(ray.collides_with(box))
		cout << " hit!";
	else
		cout << " miss!";

	cout << endl;
}*/

int main(int argc, char** argv) {
	cout << "Welcome to Fyodor!" << endl;
	/*ray ray_1(vector2d(7, 3), vector2d(-1, 0));
	aabb box(vector2d(3,3), vector2d(7, 5));

	ray_box_test(ray_1, box, "Ray 1");

	//cout << 0 * numeric_limits<float>::infinity() << endl;*/

	start_opengl(argc, argv);
	if(!initialize_opengl())
		return 1;

	/*glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
	// Quick way to make a transformation matrix
	glm::mat4 trans = glm::mat4(1.0f); // Creates an identity matrix
	trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f)); // Will build translation matrix

	vec = trans * vec;
	cout << vec.x << " " << vec.y << " " << vec.z << endl;*/

	shader_program program("./assets/vert.glvs", "./assets/frag.glfs");
	program.bind();

	texture my_texture("./assets/texture_atlas.png");
	my_texture.bind();

	// TODO: Better game loop!
	while(1)
		do_render(my_texture.get_id());
		//my_texture.render();

	return 0;
}
