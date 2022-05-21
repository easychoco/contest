#!/bin/sh

set -eu

run() {
  if [ ! $# -eq 1 ]; then 
    echo "  you need arg" 1>&2
    usage
    return 1
  fi

  if [ ! -e "${CURRENT_DIR_PATH}/${1}" ]; then
    echo "  not found:" 1>&2
    echo "    ${CURRENT_DIR_PATH}/${1}" 1>&2
    usage
    return 1
  fi

  python3 "${CURRENT_DIR_PATH}/${1}"
}

usage() {
  cat <<- END 1>&2

  Python のプログラムを実行する

    atc rin         pythno3 a.py
    atc cp rin      pythno3 a.py
END
}

run "$@"
