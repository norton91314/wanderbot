#include "wanderbot/config/config.hpp"

const double Config::VFF_MINIMUM_IGNORABLE_DISTANCE_ = 0.2;
const double Config::OBSTACLE_MINIMUM_SAFE_DISTANCE_ = 2.0;
const double Config::THROTTLE_SETTING_FORWARD_ = 1.0;
const double Config::THROTTLE_SETTING_YAW_ = 1.0;
const double Config::MAX_FORWARD_VELOCITY_ = 1.0;
const double Config::MAX_YAW_ = 1.0;
const double Config::BACK_UP_VELOCITY_ = 0.5;
const double Config::CHANGE_DIRECTION_SPIN_VELOCITY_ = 0.8;
const double Config::BACK_UP_SECONDS_ = 0.5;
const double Config::SPIN_SECONDS_ = 1.0;

double Config::getVffMinimumIgnorableDistance() const {return VFF_MINIMUM_IGNORABLE_DISTANCE_;}
double Config::getObstacleMinimumSafeDistance() const {return OBSTACLE_MINIMUM_SAFE_DISTANCE_;}
double Config::getThrottleSettingForward() const {return THROTTLE_SETTING_FORWARD_;}
double Config::getThrottleSettingYaw() const {return THROTTLE_SETTING_YAW_;}
double Config::getMaxForwardVelocity() const {return MAX_FORWARD_VELOCITY_;}
double Config::getMaxYaw() const {return MAX_YAW_;}
double Config::getBackUpVelocity() const {return BACK_UP_VELOCITY_;}
double Config::getChangeDirectionSpinVelocity() const {return CHANGE_DIRECTION_SPIN_VELOCITY_;}
double Config::getBackUpDurationSeconds() const {return BACK_UP_SECONDS_;}
double Config::getSpinDurationSeconds() const {return SPIN_SECONDS_;}
