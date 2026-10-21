#include "wanderbot/fsm/statehandler/state_handler_back_up.hpp"

Action StateHandlerBackUp::act(
  const Config & config, const double seconds_in_this_state,
  const Vector & vector_to_obstacle) const
{
  (void)seconds_in_this_state;
  (void)vector_to_obstacle;
  return Action(Velocity(config.getBackUpVelocity(), 0.0), State::GO);
}

const char * StateHandlerBackUp::getName() const {return "BackUp";}
State StateHandlerBackUp::getState() const {return State::BACK_UP;}
