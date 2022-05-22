#!/bin/sh

set -eu

#
# $1: 言語のフォルダ名
# $2: 言語の拡張子
# ex)
#   cpp cpp
#   python py
#

template() {
  if [ ! $# -eq 2 ]; then
    echo "you need 2 args."
    echo "$@"
    usage
    return 1
  fi

  TARGET_FILE="${REPOSITORY_ROOT}/${1}/template/_.${2}"

  if [ ! -e "$TARGET_FILE" ]; then
    echo "not found:"
    echo "  $TARGET_FILE"
    usage
    return 1
  fi

  clip.exe < "$TARGET_FILE"
}

usage() {
  cat <<- END 1>&2
common/template.sh
END
}

template "$@"