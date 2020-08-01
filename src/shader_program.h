// Liam Wynn, 7/31/2020, Fyodor

/*
	Defines a shader program. Essentailly you just
	give it the path to a vertex shader program and
	a fragment shader program. Then when you want to
	render with this program you bind OpenGL to use this
	program and then it gets used.
*/

#ifndef SHADER_PROGRAM
#define SHADER_PROGRAM

#include "./opengl_libs.h"
#include <string>

namespace fyodor {
	class shader_program {
		public:
			shader_program(const std::string& vert, const std::string& frag);

		private:
			/*
				Preconditions:
					- path must be a correct source code file paths.
				Postconditions:
					- Source code is read into a string which may be used
					in OpenGL.
				Side effects:
					- If file cannot be opened, it will print error
				Returns:
					- Contents of file given by path. Otherwise the empty string.
				Notes:
					- N/A
			*/
			std::string shader_source_from_file(const std::string& path);

			GLuint id;
	};
}

#endif
