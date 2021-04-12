// Liam Wynn, 3/22/2021, Fyodor

#include "./state_simulation.h"
#include "./render.h"

using namespace std;
using namespace fyodor;

state_sim::state_sim() {
}

state_sim::~state_sim() {
}

void state_sim::initialize() {
  shader = make_unique<basic_shader>();

  /* Demo code setting the shader uniforms */
  shader->bind();
	// The matrix that transforms the plane from local space to world space.
	// Matrix that will scale and rotate objects
	glm::mat4 model_matrix = glm::mat4(1.0f);
	//model_matrix = glm::rotate(model_matrix, glm::radians(0.5f), glm::vec3(1.0f, 0.0f, 0.0f));
	model_matrix = glm::translate(model_matrix, glm::vec3(200.0f, 200.0f, 0.0f));
	// Why do we need this? In local space, the width and height of the object are both 1.
	// When we apply our projection matrix, the object will have a size of 1 pixel by 1 pixel.
	// So we need to scale it according to the size of the texture.
	model_matrix = glm::scale(model_matrix, glm::vec3(16, 16, 1));
  shader->set_model_matrix(model_matrix);

	// Now transform the scene to account for the camera. TO do this, we move the
	// scene in the reverse direction of the camera. If the camera is moving to the left,
	// the whole scene moves to the right.

  // In this case, we needn't do anything.
	glm::mat4 view_matrix = glm::mat4(1.0f);
	view_matrix = glm::translate(view_matrix, glm::vec3(-100.0f, 0.0f, 0.0f));
  shader->set_view_matrix(view_matrix);

	// Finally, we want to put the scene into clip space. We define a projection
	// matrix that uses a orthogonal projection.
	glm::mat4 projection_matrix;
	//projection_matrix = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.1f, 100.0f);
	projection_matrix = glm::ortho(0.0f, 640.0f, 480.0f, 0.0f, -1.0f, 1.0f);
  shader->set_projection_matrix(projection_matrix);
  shader->unbind();

  // TODO tiles will bind atlas (which binds texture). After rendering it unbinds.
  shared_ptr<texture> map_tex = make_shared<texture>("./assets/texture_atlas.png");
  map_tex->bind();
  shared_ptr<tile_atlas> atlas = make_shared<tile_atlas>(map_tex);
  tiles = make_unique<tilemap>(10, 5, atlas);
  tiles->set_tile(3, 4, 2);
  tiles->unbind();
}

void state_sim::enter() {
}

void state_sim::process_input() {
}

void state_sim::update() {
}

void state_sim::draw() {
  // Clears color
  glClear(GL_COLOR_BUFFER_BIT);

  shader->bind();
  tiles->render();
  shader->unbind();

  // Swap window buffers at end of rendering.
  //glutSwapBuffers();
  swap_buffers();
}

void state_sim::leave() {
}

bool state_sim::quit() {
  return false;
}
