#!/bin/sh

set -eu

run() {
  if [ ! -e "$CURRENT_DIR_PATH"/a.out ]; then
    echo "  not found:" 1>&2
    echo "    ${CURRENT_DIR_PATH}/a.out" 1>&2
    usage
    return 1
  fi

  "$CURRENT_DIR_PATH"/a.out
}

usage() {
  cat <<- END 1>&2

[ cpp/run.sh ]

  C++ のプログラムを実行する

    atc run       ./a.out
    atc cp run    ./a.out
END
}

run "$@"
