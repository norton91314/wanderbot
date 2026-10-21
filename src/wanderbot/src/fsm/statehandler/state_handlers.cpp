#include "wanderbot/fsm/statehandler/state_handlers.hpp"

StateHandlers::StateHandlers()
{
  obstacle_avoider_ = new VectorForceFieldCalculator();
  state_handler_just_go_ = new StateHandlerGo(obstacle_avoider_);
  state_handler_change_direction_ = new StateHandlerChangeDirection();
  state_handler_too_near_ = new StateHandlerBackUp();
  state_handler_stand_ = new StateHandlerStand();
  state_handler_sit_ = new StateHandlerSit();
  state_handler_error_ = new StateHandlerError();
}

StateHandler * StateHandlers::get_state_handler(State state) const
{
  switch (state) {
    case State::GO:
      return state_handler_just_go_;
    case State::CHANGE_DIRECTION:
      return state_handler_change_direction_;
    case State::BACK_UP:
      return state_handler_too_near_;
    case State::STAND:
      return state_handler_stand_;
    case State::SIT:
      return state_handler_sit_;
    default:
      return state_handler_error_;
  }
}

StateHandlers::~StateHandlers()
{
  delete state_handler_just_go_;
  delete state_handler_change_direction_;
  delete state_handler_too_near_;
  delete state_handler_stand_;
  delete state_handler_sit_;
  delete state_handler_error_;
  delete obstacle_avoider_;
}
