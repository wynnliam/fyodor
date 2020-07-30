// Liam Wynn, 7/30/2020, Fyodor

#include "./render.h"

using namespace fyodor;

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
}

