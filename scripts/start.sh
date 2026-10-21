#!/bin/bash
set -e

source /opt/ros/${ROS_DISTRO}/setup.bash

ros2 launch wanderbot wanderbot.launch.py
