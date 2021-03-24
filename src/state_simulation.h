// Liam Wynn, 3/22/2021, Fyodor

/*
  Defines a state with actual units moving about.
  This is where most of the game simulation logic
  will occur.
*/

#ifndef GAME_STATE_SIM
#define GAME_STATE_SIM

#include "./state.h"

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
  };
}

#endif

