#include "wanderbot/fsm/action.hpp"

Action::Action(const Velocity & velocity, const State state)
: velocity_(velocity), state_(state) {}

Action::Action(const State state)
: velocity_(std::nullopt), state_(state) {}

std::optional<Velocity> Action::get_velocity() const {return velocity_;}

State Action::get_state() const {return state_;}
