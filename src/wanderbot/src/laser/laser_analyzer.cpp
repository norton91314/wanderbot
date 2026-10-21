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

#include "wanderbot/laser/laser_analyzer.hpp"

namespace {
std::vector<double> getNonNaNValues(const std::vector<float> & values)
{
  std::vector<double> result;
  result.reserve(values.size());
  for (const auto value : values) {
    if (std::isfinite(value)) {
      result.push_back(static_cast<double>(value));
    }
  }
  return result;
}
}  // namespace

LaserAnalyzer::LaserAnalyzer() {}

LaserCharacteristics LaserAnalyzer::determineCharacteristics(
  const double angle_min, const double angle_increment, const std::vector<float> & ranges) const
{
  LaserCharacteristics characteristics;
  characteristics.angle_min = angle_min;
  characteristics.angle_increment = angle_increment;
  characteristics.ranges = ranges;
  return characteristics;
}

Vector LaserAnalyzer::analyze(const LaserCharacteristics & characteristics,
  const std::vector<float> & ranges) const
{
  auto valid_ranges = getNonNaNValues(ranges);
  if (valid_ranges.empty()) {
    return Vector(0.0, 0.0);
  }

  double min_distance = std::numeric_limits<double>::max();
  double closest_angle = 0.0;

  for (std::size_t i = 0; i < valid_ranges.size(); ++i) {
    const double distance = valid_ranges[i];
    if (distance < min_distance) {
      min_distance = distance;
      closest_angle = characteristics.angle_min + static_cast<double>(i) * characteristics.angle_increment;
    }
  }

  return Vector(
    std::cos(closest_angle) * min_distance,
    std::sin(closest_angle) * min_distance);
}
