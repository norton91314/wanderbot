// Copyright 2023 Steve Billings
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "wanderbot/laser/laser_characteristics.hpp"

LaserCharacteristics::LaserCharacteristics() : angle_min(0.0), angle_increment(0.0) {}

LaserCharacteristics::LaserCharacteristics(double angle_min_arg, double angle_increment_arg)
: angle_min(angle_min_arg), angle_increment(angle_increment_arg) {}
