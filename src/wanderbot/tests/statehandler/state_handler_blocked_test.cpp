#include <gtest/gtest.h>

#include "wanderbot/fsm/statehandler/state_handlers.hpp"

TEST(StateHandlerBlockedTest, EntersBackUpWhenObstacleTooClose)
{
  StateHandlers handlers;
  Config config;
  Vector obstacle(0.5, 0.0);

  Action action = handlers.get_state_handler(State::GO)->act(config, 1.0, obstacle);

  EXPECT_EQ(action.get_state(), State::BACK_UP);
}
