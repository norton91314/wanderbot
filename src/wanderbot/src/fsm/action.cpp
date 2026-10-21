#include "wanderbot/fsm/action.hpp"

Action::Action(const Velocity & velocity, const State state)
: velocity_(velocity), state_(state) {}

Action::Action(const State state)
: velocity_(std::nullopt), state_(state) {}
