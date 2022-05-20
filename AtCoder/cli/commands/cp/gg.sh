#!/bin/sh

set -eu

gg() {
  # 引数がないときはさようなら
  if [ ! $# -eq 1 ]; then
    usage
    return 1
  fi

  if [ ! -e "${CURRENT_DIR_PATH}/${1}.cpp" ]; then
    echo '  unknown file:' 1>&2
    echo "    ${CURRENT_DIR_PATH}/${1}.cpp" 1>&2
    usage
    return 1;
  fi

  g++ \
    --std=gnu++17 \
    -I ~/pg/ac-library \
    -Wall \
    -Werror \
    -O2 \
    "$1".cpp
}

usage() {
  cat <<- END 1>&2

  you need args:
    ex)
      atc gg a
      atc cp gg a
END
}

gg "$@"
