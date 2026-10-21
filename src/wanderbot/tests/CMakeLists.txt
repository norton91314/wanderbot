# SPDX-License-Identifier: Apache-2.0
#
# Copyright 2023 Steve Billings
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.8)
project(wanderbot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

include_directories(include)

add_executable(wanderbot_node
  src/ros2/wanderbot_node.cpp
)

ament_target_dependencies(wanderbot_node
  rclcpp
  sensor_msgs
  geometry_msgs
)

target_include_directories(wanderbot_node PRIVATE include)

install(TARGETS wanderbot_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
