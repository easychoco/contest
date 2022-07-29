#!/bin/sh

set -eu

rin() {
  if [ ! -e "$CURRENT_DIR_PATH"/in ]; then
    echo "  not found:" 1>&2
    echo "    ${CURRENT_DIR_PATH}/in" 1>&2
    usage
    return 1
  fi

  CURRENT_DIR_PATH="$CURRENT_DIR_PATH" \
  REPOSITORY_ROOT="$REPOSITORY_ROOT" \
  "${COMMAND_ROOT}/cpp/run.sh" "$@" < "$CURRENT_DIR_PATH"/in   
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
