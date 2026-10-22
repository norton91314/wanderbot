#include "wanderbot/fsm/statehandler/state_handler_back_up.hpp"

Action StateHandlerBackUp::act(
  const Config & config, const double seconds_in_this_state,
  const Vector & vector_to_obstacle) const
{
  (void)vector_to_obstacle;

  // Back away briefly when an obstacle is detected, then return to forward motion.
  // This prevents the robot from getting stuck in a repeated BACK_UP loop.
  if (seconds_in_this_state < config.getBackUpDurationSeconds()) {
    return Action(Velocity(-config.getBackUpVelocity(), 0.0), State::BACK_UP);
  }

  return Action(Velocity::create_stopped(), State::GO);
}

const char * StateHandlerBackUp::getName() const {return "BackUp";}
State StateHandlerBackUp::getState() const {return State::BACK_UP;}
