#!/bin/bash
set -e

colcon test --packages-select wanderbot --event-handlers console_direct+
