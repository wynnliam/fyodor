// Liam Wynn, 7/30/2020, Fyodor

#include "./render.h"

#include <iostream>

using namespace fyodor;
using namespace std;

float verts[] = {
	// Positions	    // Colors	      // Texture
	// First Triangle
	-1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
	-1.0f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

	// Second Triangle
	 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
	 0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
	-1.0f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f
};

unsigned int vbo;
unsigned int vao;

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

bool fyodor::initialize_opengl() {
	// Sets the clear color to a nice, cornflower blue.
	glClearColor(0.3922f, 0.5843f, 0.9294f, 1.0f);

	// Now that we've set what we want, let us check for any errors.
	GLenum gl_err = glGetError();
	if(gl_err != GL_NO_ERROR) {
		cerr << "OpenGL Error: " << gluErrorString(gl_err) << endl;
		return false;
	}

	ilInit();

	/*glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);*/

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	return true;
}

void fyodor::do_render(const GLuint texture_id) {
	// Clears color
	glClear(GL_COLOR_BUFFER_BIT);

	glBindTexture(GL_TEXTURE_2D, texture_id);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	// Swap window buffers at end of rendering.
	glutSwapBuffers();
}
