// Liam Wynn, 8/1/2020, Fyodor

/*
	A basic class for encapsulating an OpenGL texture. This could
	be a tile atlas, a unit, or whatever.
*/

#ifndef TEXTURE
#define TEXTURE

#include <string>
#include "./opengl_libs.h"

namespace fyodor {
	class texture {
		public:
			/*
				Preconditions:
					- OpenGL is loaded and initialized
					- DevIL is loaded and initialized
				Postconditions:
					- OpenGL will have reference to this texture
					stored and ready for use
					- Will be able to render this texture
					- id is set
				Side effects:
					- None
			*/
			texture(const std::string& path);

		private:
			// When rendering texture, we need this to tell OpenGL
			// what texture to render.
			GLuint id;
	};
}

#endif
