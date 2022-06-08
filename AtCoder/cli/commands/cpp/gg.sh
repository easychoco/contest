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

  # -Werror \ <- これをつけると、warning が error になる

  g++ \
    --std=gnu++17 \
    -I "${REPOSITORY_ROOT}/../../ac-library" \
    -Wall \
    -O2 \
    "$1".cpp
}

usage() {
  cat <<- END 1>&2

[ cpp/gg.sh ]

  you need args:
    ex)
      atc gg a
      atc cp gg a
END
}

gg "$@"
