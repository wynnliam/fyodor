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

void basic_shader::set_view_matrix(const glm::mat4& view_matrix) {
	unsigned int view_loc = glGetUniformLocation(id, "view_matrix");
  if(view_loc != -1)
    glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view_matrix));
}

void basic_shader::set_projection_matrix(const glm::mat4& proj_matrix) {
	unsigned int proj_loc = glGetUniformLocation(id, "proj_matrix");
  if(proj_loc != -1)
	  glUniformMatrix4fv(proj_loc, 1, GL_FALSE, glm::value_ptr(proj_matrix));
}
