#!/bin/bash
set -e

if [ -z "$1" ]; then
  echo "Usage: $0 <task-number>"
  exit 1
fi

cd "$(dirname "$0")/.."

TASK_DIR="src/${1}_Task"

if [ -d "$TASK_DIR" ]; then
  echo "Task folder '$TASK_DIR' already exists"
  exit 1
fi

mkdir -p "$TASK_DIR"

cat > "$TASK_DIR/main.cpp" <<'EOF'
#include <iostream>
using namespace std;

/*

*/

int main()
{
  cout << "Hello World!";
  return 0;
}
EOF

echo "Created $TASK_DIR/main.cpp"
