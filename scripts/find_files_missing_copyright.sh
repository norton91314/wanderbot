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

#!/bin/bash
set -e

# Find files missing the required SPDX header.
find . -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" -o -name "*.cc" \) -print0 | while IFS= read -r -d '' file; do
  if ! grep -q "SPDX-License-Identifier" "$file"; then
    echo "$file"
  fi
done
