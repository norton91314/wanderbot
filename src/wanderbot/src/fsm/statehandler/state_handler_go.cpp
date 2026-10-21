#include "wanderbot/fsm/statehandler/state_handler_go.hpp"

#include <random>

Action StateHandlerGo::act(
  const Config & config, const double seconds_in_this_state,
  const Vector & vector_to_obstacle) const
{
  if (vector_to_obstacle.getMagnitude() < config.getObstacleMinimumSafeDistance()) {
    return Action(Velocity::create_stopped(), State::BACK_UP);
  }

  auto new_motion_vector = obstacle_avoider_->calculateNewMotionVector(config, vector_to_obstacle);
  if (std::fabs(new_motion_vector.getAngleRadians()) >= (M_PI / 2.0L)) {
    return Action(Velocity::create_stopped(), State::BACK_UP);
  }

  static std::mt19937 generator(std::random_device{}());
  static std::uniform_real_distribution<double> distribution(0.0, 1.0);

  const double posture_probability_per_second = 0.025;
  const double posture_min_duration = 1.5;

  if (seconds_in_this_state > posture_min_duration &&
      distribution(generator) < posture_probability_per_second) {
    const bool sit = distribution(generator) < 0.5;
    return Action(Velocity::create_stopped(), sit ? State::SIT : State::STAND);
  }

  auto new_velocity = Velocity(
    new_motion_vector.getMagnitude() * config.getThrottleSettingForward(),
    new_motion_vector.getAngleRadians() * config.getThrottleSettingYaw());
  return Action(new_velocity, State::GO);
}

const char * StateHandlerGo::getName() const {return "Go";}
State StateHandlerGo::getState() const {return State::GO;}
