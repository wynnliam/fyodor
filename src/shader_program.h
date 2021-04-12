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
			~shader_program();

			/*
				Preconditions:
					- Program properly loaded, compiled, and linked. This is
					done on construction of program.
				Postconditions:
					- OpenGL now uses this program for rendering.
				Side-effects:
					- None
				Returns:
					- None
				Notes:
					- I'm not sure what happens if the program fails in loading,
					compiling, or linking steps.
			*/
			void bind();
      void unbind();

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

			/*
				Preconditions:
					- Shader source code read from file (please use shader_source_from_file).
				Postconditions:
					- OpenGL will compile and store shader for future use.
				Side-effects:
					- Depending on shader_type, vert_id or frag_id will be set.
					- If source code is bad, there will be an error printed.
				Returns:
					- N/A
				Notes:
					- If shader fails to compile, then compile_successfully will be set
					to false.
			*/
			void compile_shader_subprogram(const std::string& src, GLenum shader_type, GLuint& shader_id);

			/*
				Preconditions:
					- Both vertex and fragment shader programs compiled without error.
				Postconditions:
					- Vertex and frament shaders are linked to overall shader program
				Side-effects:
					- In the event of failure, error log will be printed.
					- May set linked_successfully to false.
				Returns:
					- None
				Notes:
					- If link fails, please see log printed.
			*/
			void link_shader_program();

			/*
				Preconditions:
					- Had to try and compile program.
				Postconditions:
					- Will print any shader subprogram errors that may be found.
				Side effects:
					- None
				Returns:
					- N/A
				Notes:
					- Will only print compile failures.
				
			*/
			void shader_subprogram_compile_log(const GLuint& shader_id);

			/*
				Preconditions:
					- Had to try and link program.
				Postconditions:
					- Will print any shader program errors that may be found.
				Side effects:
					- None
				Returns:
					- N/A
				Notes:
					- Will only print link failures.
				
			*/
			void shader_program_link_log();

			// If either vertex or fragment shaders fail to be compiled, we have this set
			// to false. Otherwise it is set to true.
			bool compiled_successfully;
			// If program fails to link, we set this to false. By default it is true though.
			bool linked_successfully;

    protected:
			// We use these ids when we want to tell OpenGL to use this program
			// for rendering.
			GLuint id;
			// Id's for the individual vertex and fragment shader
			// subprograms.
			GLuint vert_id, frag_id;
	};
}

#endif
