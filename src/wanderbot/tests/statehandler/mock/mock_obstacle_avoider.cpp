#include "wanderbot/fsm/statehandler/state_handlers.hpp"
#include "wanderbot/motion/obstacle_avoider.hpp"

class MockObstacleAvoider : public ObstacleAvoider
{
public:
  Vector calculateNewMotionVector(const Config & config, const Vector & vector_to_obstacle) const override
  {
    (void)config;
    return vector_to_obstacle;
  }
};
