#!/bin/bash
set -e

find src -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) -print0 | while IFS= read -r -d '' file; do
  clang-format -i "$file"
done
