#!/bin/sh

set -eu

rin() {
  if [ ! -e "$CURRENT_DIR_PATH"/in ]; then
    echo base
    echo "  not found:" 1>&2
    echo "    ${CURRENT_DIR_PATH}/in" 1>&2
    usage
    return 1
  fi

  CURRENT_DIR_PATH="$CURRENT_DIR_PATH" \
  REPOSITORY_ROOT="$REPOSITORY_ROOT" \
  "${COMMAND_ROOT}/python/run.sh" "$@" < "$CURRENT_DIR_PATH"/in   
}

usage() {
  cat <<- END 1>&2

[ python/rin.sh ]

  Python のプログラムを実行する

    atc rin a       pythno3 a.py < in
    atc cp rin a    pythno3 a.py < in
END
}

rin "$@"
