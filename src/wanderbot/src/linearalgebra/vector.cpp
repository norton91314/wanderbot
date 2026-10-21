#include "wanderbot/linearalgebra/vector.hpp"

Vector::Vector() : x_(0.0), y_(0.0) {}
Vector::Vector(double x, double y) : x_(x), y_(y) {}

double Vector::getX() const {return x_;}
double Vector::getY() const {return y_;}

double Vector::getMagnitude() const {return std::hypot(x_, y_);}

double Vector::getAngleRadians() const {return std::atan2(y_, x_);}
