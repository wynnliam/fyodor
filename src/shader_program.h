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
			GLuint id;
	};
}

#endif
