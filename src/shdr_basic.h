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
  };
}

#endif
