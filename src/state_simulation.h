// Liam Wynn, 3/22/2021, Fyodor

/*
  Defines a state with actual units moving about.
  This is where most of the game simulation logic
  will occur.
*/

#ifndef GAME_STATE_SIM
#define GAME_STATE_SIM

#include <memory>
#include "./state.h"
//#include "./shader_program.h"
#include "./shdr_basic.h"
#include "./tilemap.h"
#include "./tile_atlas.h"

namespace fyodor {
  class state_sim : public gamestate {
    public:
      state_sim();
      ~state_sim();

      void initialize();
      void enter();
      void process_input();
      void update();
      void draw();
      void leave();
      bool quit();

    private:
      std::unique_ptr<basic_shader> shader;
      std::unique_ptr<tilemap> tiles;
  };
}

#endif

