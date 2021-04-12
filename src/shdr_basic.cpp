// Liam Wynn, 4/12/2021, Fyodor

#include "./shdr_basic.h"

using namespace fyodor;

basic_shader::basic_shader() : shader_program("./assets/vert.glvs", "./assets/frag.glfs") {
}

void basic_shader::set_model_matrix(const glm::mat4& model_matrix) {
	unsigned int model_loc = glGetUniformLocation(id, "model_matrix");
  if(model_loc != -1)
	  glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model_matrix));
}

