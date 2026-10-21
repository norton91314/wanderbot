#include "wanderbot/fsm/statehandler/state_handler_error.hpp"

Action StateHandlerError::act(
  const Config & config, const double seconds_in_this_state,
  const Vector & vector_to_obstacle) const
{
  (void)config;
  (void)seconds_in_this_state;
  (void)vector_to_obstacle;
  return Action(Velocity::create_stopped(), State::ERROR);
}

const char * StateHandlerError::getName() const {return "Error";}
State StateHandlerError::getState() const {return State::ERROR;}
