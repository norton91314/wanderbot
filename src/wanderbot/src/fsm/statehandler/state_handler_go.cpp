#include "wanderbot/fsm/statehandler/state_handler_go.hpp"

#include <random>

Action StateHandlerGo::act(
   const Config & config, const double seconds_in_this_state,
   const Vector & vector_to_obstacle) const
{
  (void)seconds_in_this_state;

  if (vector_to_obstacle.getMagnitude() < config.getObstacleMinimumSafeDistance()) {
    return Action(Velocity::create_stopped(), State::BACK_UP);
  }

  auto new_motion_vector = obstacle_avoider_->calculateNewMotionVector(config, vector_to_obstacle);
  if (std::fabs(new_motion_vector.getAngleRadians()) >= (M_PI / 2.0L)) {
    return Action(Velocity::create_stopped(), State::BACK_UP);
  }

  auto new_velocity = Velocity(
    new_motion_vector.getMagnitude() * config.getThrottleSettingForward(),
    new_motion_vector.getAngleRadians() * config.getThrottleSettingYaw());
  return Action(new_velocity, State::GO);
}

const char * StateHandlerGo::getName() const {return "Go";}
State StateHandlerGo::getState() const {return State::GO;}
