// Liam Wynn, 7/31/2020, Fyodor

#include "./shader_program.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace fyodor;
using namespace std;

shader_program::shader_program(const string& vert, const string& frag) {
	// First, we begin by creating a gl program id. This id is used
	// to tell OpenGL that we want to use this particular program.
	id = glCreateProgram();

	// Next, we need to read our shader source code
	string vert_src, frag_src;
	vert_src = shader_source_from_file(vert);
	frag_src = shader_source_from_file(frag);

	// Now load and compile the source code.
	// Assume true for now. If either fail we set to false.
	compiled_successfully = true;
	compile_shader_subprogram(vert_src, GL_VERTEX_SHADER, vert_id);
	compile_shader_subprogram(frag_src, GL_FRAGMENT_SHADER, frag_id);
}

string shader_program::shader_source_from_file(const string& path) {
	string result = "";

	ifstream in(path);

	if(in.is_open()) {
		stringstream buffer;
		buffer << in.rdbuf();

		result = buffer.str();
	} else {
		cout << "Error: bad shader file path: " << path << endl;
	}

	return result;
}

void shader_program::compile_shader_subprogram(const string& src, GLenum shader_type, GLuint& shader_id) {
	// Generates the shader id
	shader_id = glCreateShader(shader_type);

	// Loads the shader program into OpenGL
	const char* src_raw = src.c_str();
	const char** raw_as_array = (const char**)&src_raw;
	glShaderSource(shader_id, 1, raw_as_array, NULL);
	// Now compile it.
	glCompileShader(shader_id);

	// Now check for errors.
	GLint compile_status;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compile_status);

	if(compile_status != GL_TRUE) {
		// TODO: What error?
		cout << "There was an error compiling shader" << endl;
		compiled_successfully = false;
	}
}
