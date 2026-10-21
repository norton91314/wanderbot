#include "wanderbot/fsm/statehandler/state_handler_change_direction.hpp"

Action StateHandlerChangeDirection::act(
  const Config & config, const double seconds_in_this_state,
  const Vector & vector_to_obstacle) const
{
  (void)vector_to_obstacle;
  if (seconds_in_this_state >= config.getSpinDurationSeconds()) {
    return Action(Velocity::create_stopped(), State::GO);
  }
  return Action(Velocity(0.0, config.getChangeDirectionSpinVelocity()), State::CHANGE_DIRECTION);
}

const char * StateHandlerChangeDirection::getName() const {return "ChangeDirection";}
State StateHandlerChangeDirection::getState() const {return State::CHANGE_DIRECTION;}
