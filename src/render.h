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

	void start_opengl(int argc, char** argv);
}

#endif
