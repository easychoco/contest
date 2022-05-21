#!/bin/sh

set -eu

rin() {
  if [ ! $# -eq 1 ]; then 
    echo "  you need arg" 1>&2
    usage
    return 1
  fi

  if [ ! -e "${CURRENT_DIR_PATH}/${1}".py ]; then
    echo "  not found:" 1>&2
    echo "    ${CURRENT_DIR_PATH}/${1}.py" 1>&2
    usage
    return 1
  fi

  if [ ! -e "$CURRENT_DIR_PATH"/in ]; then
    echo base
    echo "  not found:" 1>&2
    echo "    ${CURRENT_DIR_PATH}/in" 1>&2
    usage
    return 1
  fi

  python3 "${CURRENT_DIR_PATH}/${1}.py" < "$CURRENT_DIR_PATH"/in
}

usage() {
  cat <<- END 1>&2

  Python のプログラムを実行する

    atc rin a       pythno3 a.py < in
    atc cp rin a    pythno3 a.py < in
END
}

rin "$@"
