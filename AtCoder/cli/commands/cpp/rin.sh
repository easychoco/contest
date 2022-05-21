#!/bin/sh

set -eu

rin() {
  if [ ! -e "$CURRENT_DIR_PATH"/a.out ]; then
    echo "  not found:" 1>&2
    echo "  ${CURRENT_DIR_PATH}/a.out" 1>&2
    usage
    return 1
  fi

  if [ ! -e "$CURRENT_DIR_PATH"/in ]; then
    echo "  not found:" 1>&2
    echo "    ${CURRENT_DIR_PATH}/in" 1>&2
    usage
    return 1
  fi

  "$CURRENT_DIR_PATH"/a.out < "$CURRENT_DIR_PATH"/in
}

usage() {
  cat <<- END 1>&2

[ cpp/rin.sh ]

  C++ のプログラムを実行する

    atc rin        ./a.out < in
    atc cp rin     ./a.out < in
END
}

rin "$@"
