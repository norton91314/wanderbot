#include <gtest/gtest.h>

#include "wanderbot/motion/vff/vector_force_field_calculator.hpp"

TEST(VectorForceFieldCalculatorTest, ReturnsZeroOnCloseObstacle)
{
  VectorForceFieldCalculator calc;
  Config config;
  Vector obstacle(0.5, 0.0);

  Vector result = calc.calculateNewMotionVector(config, obstacle);

  EXPECT_EQ(result.getMagnitude(), 0.0);
}
