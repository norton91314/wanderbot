#!/bin/bash
set -e

find . -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) -print0 | while IFS= read -r -d '' file; do
  if ! grep -q "SPDX-License-Identifier" "$file"; then
    echo "$file"
  fi
done
