#!/bin/sh

set -eu

cargo() {
  # 引数がないときはさようなら
  if [ ! $# -eq 1 ]; then
    usage
    return 1
  fi

  if [ ! -e "${CURRENT_DIR_PATH}/${1}.rust" ]; then
    echo '  unknown file:' 1>&2
    echo "    ${CURRENT_DIR_PATH}/${1}.rust" 1>&2
    usage
    return 1;
  fi

  # -Werror \ <- これをつけると、warning が error になる

  cargo build
}

usage() {
  cat <<- END 1>&2

[ rust/cargo.sh ]

  you need args:
    ex)
      atc gg a
      atc cp gg a
END
}

cargo "$@"
