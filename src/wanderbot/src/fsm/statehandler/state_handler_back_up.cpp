#include "wanderbot/fsm/statehandler/state_handler_back_up.hpp"

Action StateHandlerBackUp::act(
  const Config & config, const double seconds_in_this_state,
  const Vector & vector_to_obstacle) const
{
  if (seconds_in_this_state < config.getBackUpDurationSeconds()) {
    return Action(Velocity(-config.getBackUpVelocity(), 0.0), State::BACK_UP);
  }

  if (vector_to_obstacle.getMagnitude() < config.getObstacleMinimumSafeDistance()) {
    return Action(Velocity(0.0, config.getChangeDirectionSpinVelocity()), State::CHANGE_DIRECTION);
  }

  return Action(Velocity::create_stopped(), State::GO);
}

const char * StateHandlerBackUp::getName() const {return "BackUp";}
State StateHandlerBackUp::getState() const {return State::BACK_UP;}
