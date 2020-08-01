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

	// Now that we compiled, we will attach the shader subprograms to
	// our overall program and then link it
	link_shader_program();
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
		cout << "There was an error compiling shader: " << shader_id << endl;
		shader_subprogram_compile_log(shader_id);
		compiled_successfully = false;
	}
}

void shader_program::link_shader_program() {
	glAttachShader(id, vert_id);
	glAttachShader(id, frag_id);
	glLinkProgram(id);

	// Now check for errors.
	GLint link_status;
	glGetProgramiv(id, GL_LINK_STATUS, &link_status);
	if(link_status != GL_TRUE) {
		cout << "There was a problem linking shader program: " << id << endl;
		shader_program_link_log();
	}
}

void shader_program::shader_subprogram_compile_log(const GLuint& shader_id) {
	int log_len, max_log_len;
	char* log;

	// Get the maximum possible length of the log.
	glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &max_log_len);

	log = new char[max_log_len];

	// Now get the info log.
	glGetShaderInfoLog(shader_id, max_log_len, &log_len, log);

	if(log_len > 0)
		cout << log << endl;

	delete[] log;
	log = NULL;
}

void shader_program::shader_program_link_log() {
	int log_len, max_log_len;
	char* log;

	// Get the maximum possible length of the log.
	glGetProgramiv(id, GL_INFO_LOG_LENGTH, &max_log_len);

	log = new char[max_log_len];

	// Now get the info log.
	glGetProgramInfoLog(id, max_log_len, &log_len, log);

	if(log_len > 0)
		cout << log << endl;

	delete[] log;
	log = NULL;
}
