#include "wanderbot/fsm/statehandler/state_handler_stand.hpp"

#include <random>

Action StateHandlerStand::act(
  const Config & config, const double seconds_in_this_state,
  const Vector & vector_to_obstacle) const
{
  (void)config;
  (void)vector_to_obstacle;

  static std::mt19937 generator(std::random_device{}());
  static std::uniform_real_distribution<double> distribution(1.0, 3.0);

  if (seconds_in_this_state > distribution(generator)) {
    return Action(Velocity::create_stopped(), State::GO);
  }

  return Action(Velocity::create_stopped(), State::STAND);
}

const char * StateHandlerStand::getName() const {return "Stand";}
State StateHandlerStand::getState() const {return State::STAND;}
