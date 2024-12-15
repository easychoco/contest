#!/bin/sh

set -eu

run() {
  if [ ! $# -eq 1 ]; then
    echo "  you need arg" 1>&2
    usage
    return 1
  fi

  TARGET_FILE="${CURRENT_DIR_PATH}/${1}.py"

  if [ ! -e "${TARGET_FILE}" ]; then
    echo "  not found:" 1>&2
    echo "    ${TARGET_FILE}" 1>&2
    usage
    return 1
  fi

  python3 "${TARGET_FILE}"
}

usage() {
  cat <<-END 1>&2

[ python/run.sh ]

  Python のプログラムを実行する

    atc rin         python3 a.py
    atc cp rin      python3 a.py
END
}

run "$@"
