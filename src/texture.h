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

			GLuint get_id() const { return id; }

			unsigned int get_width() const { return width; }
			unsigned int get_height() const { return height; }

			/*
				Preconditions:
					- Texture successfully loaded.
				Postconditions:
					- Will set this texture as the one
					we want to render.
				Side effects:
					- Will update OpenGL internally so
					that this texture is the one we use.
				Returns:
					- N/A
				Notes:
					- Be sure to call unbind when done using
					the texture!
			*/
			void bind();

			/*
				Preconditions:
					- Texture must be bound (please call bind)
				Postconditions:
					- Texture not bound in OpenGL.
					- Corollary: Can bind another texture
					to render.
				Side effects:
					- OpenGL modified so that no texture is bound.
				Returns:
					- N/A
				Notes:
					- Be sure to bind texture before calling this!
			*/
			void unbind();

			/*
				Temporary render function
			*/
			void render();

		private:
			// When rendering texture, we need this to tell OpenGL
			// what texture to render.
			GLuint id;

			// Texture dimensions in pixels
			unsigned int width, height;
	};
}

#endif
