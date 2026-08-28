#!/bin/bash
set -e

if [ -z "$1" ]; then
  echo "Usage: $0 <task-number>"
  exit 1
fi

cd "$(dirname "$0")/.."

TASK_DIR=$(find src -maxdepth 1 -type d -name "${1}_*" | head -n 1)

if [ -z "$TASK_DIR" ]; then
  echo "No task folder found for '$1' in src/"
  exit 1
fi

echo ""
echo "--- Fordítás ---"
time g++ -std=c++17 -o "$TASK_DIR/main" "$TASK_DIR/main.cpp"

echo ""
echo "--- Futtatás ---"
echo ""

time "./$TASK_DIR/main"
