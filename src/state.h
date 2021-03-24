// Liam Wynn, 3/22/2021, Fyodor

/*
  Essentially, the engine is a giant finite state machine.
  At any given time, you are in some state which you check for
  keyboard inputs, perform update logic, then render.
*/

#ifndef STATE
#define STATE

namespace fyodor {
  class gamestate {
    public:
      gamestate();
      virtual ~gamestate();

      // Called once before entering the gameloop.
      virtual void initialize() = 0;
      // Called when entering this state.
      virtual void enter() = 0;
      // Called whenever an input even occurs.
      virtual void process_input() = 0;
      // Called every frame to do a step of game logic.
      virtual void update() = 0;
      // Called every frame to do a step of rendering.
      virtual void draw() = 0;
      // Called when leaving the state.
      virtual void leave() = 0;
      // If true, we will terminate the application.
      virtual bool quit() = 0;
  };
}

#endif
