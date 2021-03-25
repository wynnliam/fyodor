// Liam Wynn, 7/30/2020, Fyodor

/*
  TODO: Glut is fine for a strictly interactive (ie do thing, then response).
  However, since we want to handle realtime logic, GLFW is the way to go:

  https://gamedev.stackexchange.com/questions/8623/a-good-way-to-build-a-game-loop-in-opengl
*/

#ifndef OPENGL_LIBS
#define OPENGL_LIBS

/* GLFW Windowing utility*/
#include <GLFW/glfw3.h>
/*Freeglut windowing utility*/
#include <GL/freeglut.h>
/*OpenGL itself -- we're using gl3 from now on for shader programs*/
#include <GLES3/gl32.h>
/*OpenGL utilities*/
#include <GL/glu.h>

/* GLM headers */
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*IL library - the base library to load, save, and convert images*/
#include <IL/il.h>
/*IL Utilities library - mid level library for image manipulation*/
#include <IL/ilu.h>

#endif
