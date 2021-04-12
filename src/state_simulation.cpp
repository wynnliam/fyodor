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
