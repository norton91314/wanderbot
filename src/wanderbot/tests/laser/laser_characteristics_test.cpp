#include <gtest/gtest.h>

#include "wanderbot/laser/laser_characteristics.hpp"

TEST(LaserCharacteristicsTest, InitializesValues)
{
  LaserCharacteristics characteristics(0.25, 0.1);

  EXPECT_DOUBLE_EQ(characteristics.angle_min, 0.25);
  EXPECT_DOUBLE_EQ(characteristics.angle_increment, 0.1);
}
