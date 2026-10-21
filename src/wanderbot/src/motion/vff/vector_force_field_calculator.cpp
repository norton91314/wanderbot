#include "wanderbot/motion/vff/vector_force_field_calculator.hpp"

Vector VectorForceFieldCalculator::calculateNewMotionVector(
  const Config & config, const Vector & vector_to_obstacle) const
{
  (void)config;
  const double distance = vector_to_obstacle.getMagnitude();
  if (distance <= config.getVffMinimumIgnorableDistance()) {
    return Vector(0.0, 0.0);
  }

  if (distance < config.getObstacleMinimumSafeDistance()) {
    return Vector(0.0, 0.0);
  }

  return vector_to_obstacle;
}
