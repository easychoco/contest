#!/bin/sh

set -eu

if [ ! $# -eq 1 ]; then
  echo "you need one args."
  return 1
fi

TARGET_CPP_FILE="${REPOSITORY_ROOT}/cpp/mono/${1}.cpp"

if [ -e "$TARGET_CPP_FILE" ]; then
  echo "$1" is already exist.
else
  echo "create mono/${1}.cpp"
  cp "${REPOSITORY_ROOT}/cpp/template/_.cpp" "$TARGET_CPP_FILE"
fi

echo "opening mono/${1}"...
code "${REPOSITORY_ROOT}/cpp" \
  "${REPOSITORY_ROOT}/cpp/_tips.cpp" \
  "${REPOSITORY_ROOT}/cpp/mono/in" \
  "$TARGET_CPP_FILE"
echo done.
