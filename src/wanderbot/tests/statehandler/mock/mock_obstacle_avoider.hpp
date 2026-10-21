#ifndef WANDERBOT__TESTS__STATEHANDLER__MOCK__MOCK_OBSTACLE_AVOIDER_HPP_
#define WANDERBOT__TESTS__STATEHANDLER__MOCK__MOCK_OBSTACLE_AVOIDER_HPP_

#include "wanderbot/motion/obstacle_avoider.hpp"

class MockObstacleAvoider : public ObstacleAvoider
{
public:
  Vector calculateNewMotionVector(const Config & config, const Vector & vector_to_obstacle) const override;
};

#endif  // WANDERBOT__TESTS__STATEHANDLER__MOCK__MOCK_OBSTACLE_AVOIDER_HPP_
