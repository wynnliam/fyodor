// Liam Wynn, 7/30/2020, Fyodor

#include "./render.h"

#include <iostream>

using namespace fyodor;
using namespace std;

static GLFWwindow* window;

void fyodor::start_opengl(int argc, char** argv) {
  if(!glfwInit()) {
    cout << "Error initializing GLFW" << endl;
    exit(-1);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_DOUBLEBUFFER, 1);
  glfwWindowHint(GLFW_DEPTH_BITS, 1);
  glfwWindowHint(GLFW_SAMPLES, 1);

  window = glfwCreateWindow(SCREEN_W, SCREEN_H, "Fyodor", NULL, NULL);
  if(!window) {
    cout << "Error creating window" << endl;
    glfwTerminate();
    exit(-1);
  }

  glfwMakeContextCurrent(window);
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

	return true;
}

void fyodor::swap_buffers() {
  glfwSwapBuffers(window);
}

void fyodor::clean_up_opengl() {
  glfwDestroyWindow(window);
  glfwTerminate();
}
