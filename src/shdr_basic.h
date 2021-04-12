// Liam Wynn, 4/12/2021, Fyodor

/*
  Defines a simple shader program that uses the vert and frag subprograms.
  The typical workflow is: define a shader program glvs and glfs. Then create
  a corresponding class for that.
*/

#ifndef SHDR_BASIC
#define SHDR_BASIC

#include "./shader_program.h"

namespace fyodor {
  class basic_shader : public shader_program {
    public:
      basic_shader();

      /*
        Preconditions:
          - Program compiled successfully (done on construction of object)
        Postconditions:
          - Sets the modelview matrix in the vert.glvs shader
        Side-effects:
          - Does effect internal OpenGL state machine by chaging value!
        Arguments:
          - model_matrix: the matrix itself
        Notes:
          - If operation somehow fails, the matrix is not set
      */
      void set_model_matrix(const glm::mat4& model_matrix);
  };
}

#endif
