#include <gtest/gtest.h>

#include "wanderbot/fsm/statehandler/state_handlers.hpp"

TEST(StateHandlerGoTest, KeepsGoingWhenClear)
{
  StateHandlers handlers;
  Config config;
  Vector obstacle(10.0, 0.0);

  Action action = handlers.get_state_handler(State::GO)->act(config, 1.0, obstacle);

  EXPECT_EQ(action.get_state(), State::GO);
}
