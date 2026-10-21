cmake_minimum_required(VERSION 3.8)
project(wanderbot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

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
  src/linearalgebra/vector.cpp
  src/motion/velocity.cpp
  src/motion/vff/vector_force_field_calculator.cpp
)

ament_target_dependencies(wanderbot_lib
  rclcpp
)

install(TARGETS wanderbot_lib
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/
  DESTINATION include
)

ament_package()
