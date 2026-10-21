#include <gtest/gtest.h>

#include "wanderbot/laser/laser_analyzer.hpp"
#include "wanderbot/linearalgebra/vector.hpp"

TEST(LaserAnalysisTest, DetectsClosestObstacle)
{
  LaserAnalyzer analyzer;
  LaserCharacteristics characteristics(0.0, 0.1);
  std::vector<float> ranges = {10.0f, 10.0f, 2.0f, 10.0f};

  Vector result = analyzer.analyze(characteristics, ranges);

  EXPECT_NEAR(result.getMagnitude(), 2.0, 1e-6);
}
