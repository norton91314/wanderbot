#include "wanderbot/motion/velocity.hpp"

Velocity::Velocity() : linear_(0.0), angular_(0.0) {}
Velocity::Velocity(double linear, double angular) : linear_(linear), angular_(angular) {}

Velocity Velocity::create_stopped() {return Velocity(0.0, 0.0);}

double Velocity::getLinear() const {return linear_;}
double Velocity::getAngular() const {return angular_;}
