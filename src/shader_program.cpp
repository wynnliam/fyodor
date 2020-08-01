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

	cout << "From: " << vert << endl;
	cout << vert_src << endl;

	cout << "\nFrom: " << frag << endl;
	cout << frag_src << endl;
}

string shader_program::shader_source_from_file(const string& path) {
	string result = "";

	ifstream in(path);

	if(in.is_open()) {
		stringstream buffer;
		buffer << in.rdbuf();

		result = buffer.str();
	}

	return result;
}

