// Liam Wynn, 7/30/2020, Fyodor

/*
	For now, this is just a temporary place to handle all rendering
	logic. It'll be a playground for rendering stuff. Later on, I
	might nix it for a more sophisticated system.
*/

#ifndef RENDER_HANDLING
#define RENDER_HANDLING

#include "./opengl_libs.h"

namespace fyodor {
	// Screen dimensions in pixels
	const unsigned int SCREEN_W = 640;
	const unsigned int SCREEN_H = 480;
	// Frames per second
	const unsigned int SCREEN_FPS = 30;

	/*
		Preconditions:
			- None
		Postconditions:
			- Creates a valid OpenGL context.
		Side Effects:
			- None
		Returns:
			- N/A
		Notes:
			- Please call this in main as early as possible.
			No other rendering may be done without this.
			- TODO: This is apart of a temporary system while I get
			my bearings with OpenGL. This may be totally deprecated
			in the future.
	*/
	void start_opengl(int argc, char** argv);
	
	/*
		Preconditions:
			- A valid OpenGL context (IE: call start_oepngl).
		Postconditions:
			- Opengl is set and ready to run.
			- DevIL is initialized and ready to run
		Side Effects:
			- Initializes Projection and Modelview matricies
				- Projection matrix is set to orthographic
				- Modelview is just identity.
			- GL flags set
			- GL clear color is set
			- Will print to window
		Returns:
			false - Something failed. Please terminate application.
			true - No errors in spinning up OpenGL.
		Notes:
			- TODO: This is apart of a temporary system while I get
			my bearings with OpenGL. This may be totally deprecated
			in the future.
	*/
	bool initialize_opengl();

  /*
    A simple wrapper to invoke OpenGL glSwapBuffers.

    Preconditions:
      - OpenGL initialized with a valid Context.
  */
  void swap_buffers();

  /*
    Preconditions:
      - Valid OpenGL context and window created.
    Postconditions:
      - Destorys the OpenGL context and window
      - Terminates glfw
  */
  void clean_up_opengl();
}

#endif
