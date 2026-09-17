#!/bin/bash
set -e

if [ -z "$1" ]; then
  echo "Usage: $0 <task-number>"
  exit 1
fi

cd "$(dirname "$0")/.."

DECADE=$(( (10#$1 / 10) * 10 ))
TASK_DIR="src/${DECADE}_Tasks/${1}_Task"

if [ -d "$TASK_DIR" ]; then
  echo "Task folder '$TASK_DIR' already exists"
  exit 1
fi

mkdir -p "$TASK_DIR"

cat > "$TASK_DIR/main.cpp" <<'EOF'
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include "../../common/math.h"
#include "../../common/primes.h"
#include "../../common/sort.h"
#include "../../common/string.h"

using namespace std;

/*

*/

int main()
{
  cout << "Result: " << "0" << std::endl;
  return 0;
}
EOF

echo "Created $TASK_DIR/main.cpp"
