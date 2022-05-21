#!/bin/sh

set -eu

#
# $1: 言語のフォルダ名
# $2: 言語の拡張子
# $3: コンテストのフォルダ名
# ex)
#   cpp cpp abc123-d
#   python py abc123-d
#

mono() {
  if [ ! $# -eq 3 ]; then
    echo "you need 3 args."
    echo "$@"
    usage
    return 1
  fi

  LANGUAGE_ROOT="${REPOSITORY_ROOT}/${1}"
  EXT="$2"
  TARGET_FILE="${LANGUAGE_ROOT}/mono/${3}.${EXT}"

  if [ -e "$TARGET_FILE" ]; then
    echo "${3} is already exist."
  else
    echo "create mono/${3}.${EXT}"
    cp "${LANGUAGE_ROOT}/template/_.${EXT}" "$TARGET_FILE"
  fi

  echo "opening mono/${3}.${EXT}..."
  code "${LANGUAGE_ROOT}" \
    "${LANGUAGE_ROOT}/_tips.${EXT}" \
    "${LANGUAGE_ROOT}/mono/in" \
    "$TARGET_FILE"
  echo "done."
  echo "  ${LANGUAGE_ROOT}/mono"
}

usage() {
  cat <<- END 1>&2

[ common/mono.sh ]
END
}

mono "$@"
