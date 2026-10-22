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

add_library(wanderbot_lib
  src/config/config.cpp
  src/fsm/action.cpp
  src/fsm/statehandler/state_handler_back_up.cpp
  src/fsm/statehandler/state_handler_change_direction.cpp
  src/fsm/statehandler/state_handler_error.cpp
  src/fsm/statehandler/state_handler_go.cpp
  src/fsm/statehandler/state_handler_sit.cpp
  src/fsm/statehandler/state_handler_stand.cpp
  src/fsm/statehandler/state_handlers.cpp
  src/laser/laser_analyzer.cpp
  src/laser/laser_characteristics.cpp
  src/linearalgebra/vector.cpp
  src/motion/velocity.cpp
  src/motion/vff/vector_force_field_calculator.cpp
)

ament_target_dependencies(wanderbot_lib
  rclcpp
  sensor_msgs
  geometry_msgs
)

add_executable(wanderbot_node
  src/ros2/wanderbot_node.cpp
)

ament_target_dependencies(wanderbot_node
  rclcpp
  sensor_msgs
  geometry_msgs
)

target_link_libraries(wanderbot_node wanderbot_lib)

target_include_directories(wanderbot_node PRIVATE include)

install(TARGETS wanderbot_lib wanderbot_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../gazeboworlds
  DESTINATION share
)

ament_package()
