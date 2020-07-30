// Liam Wynn, 7/30/2020, Fyodor

#include "./render.h"

#include <iostream>

using namespace fyodor;
using namespace std;

void fyodor::start_opengl(int argc, char** argv) {
	// First, we initialize glut.
	glutInit(&argc, argv);
	// Create an OpenGL 3.0 context
	glutInitContextVersion(3, 0);

	// Create a double-buffered window
	// GLUT_DEPTH fixes draw order for faces.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_MULTISAMPLE | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_W, SCREEN_H);
	glutCreateWindow("Fyodor");

	// Bind callbacks here
	glutCloseFunc(fyodor::opengl_cleanup);
}

bool fyodor::initialize_opengl() {
	// Sets OpenGL flags.
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Sets the projection matrix. This effectively defines
	// our camera.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_W, -SCREEN_H, 0, 0.01, 100);

	// Sets how things are transformed. For now, we need
	// only to initialize this to the identity matrix. When
	// we do other forms of rendering we will always use this
	// matrix.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Sets the clear color to a nice, cornflower blue.
	glClearColor(0.3922f, 0.5843f, 0.9294f, 1.0f);

	// Now that we've set what we want, let us check for any errors.
	GLenum gl_err = glGetError();
	if(gl_err != GL_NO_ERROR) {
		cerr << "OpenGL Error: " << gluErrorString(gl_err) << endl;
		return false;
	}

	return true;
}

void fyodor::do_render() {
	// Clears color
	glClear(GL_COLOR_BUFFER_BIT);

	// Swap window buffers at end of rendering.
	glutSwapBuffers();
}

void fyodor::opengl_cleanup() {
	cout << "Cleaning up OpenGL" << endl;
}
