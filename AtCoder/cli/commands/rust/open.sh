#!/bin/sh

set -eu

#
# $1: 言語のフォルダ名
# $2: 言語の拡張子
# $3: コンテストのフォルダ名
# $4: コンテストの番号
# ex)
#   cpp cpp abc 123
#   python py abc 123
#

open() {
  if [ ! $# -eq 4 ]; then
    echo "you need 4 args." 1>&2
    usage
    return 1
  fi

  LANGUAGE_ROOT="${REPOSITORY_ROOT}/${1}"
  EXT="$2"

  if [ ! -e "${LANGUAGE_ROOT}/${3}" ]; then
    echo "${3} is not exist." 1>&2
    echo "not create ${LANGUAGE_ROOT}/${3}/${4}. bye." 1>&2
    usage
    return 1
  fi

  TARGET_CONTEST_FOLDER="${LANGUAGE_ROOT}/${3}/${4}"
  TEMPLATE_FOLDER="${LANGUAGE_ROOT}/template"
  CONTEST_NAME_PATH="${3}/${4}"

  if [ -e "$TARGET_CONTEST_FOLDER" ]; then
    echo "${4} is already exist." 1>&2
  else
    echo "creating ${CONTEST_NAME_PATH}..." 1>&2
    mkdir -p "$TARGET_CONTEST_FOLDER"
    cp "${TEMPLATE_FOLDER}/_.${EXT}" "${TARGET_CONTEST_FOLDER}/a.${EXT}"
    cp "${TEMPLATE_FOLDER}/_.${EXT}" "${TARGET_CONTEST_FOLDER}/b.${EXT}"
    cp "${TEMPLATE_FOLDER}/_.${EXT}" "${TARGET_CONTEST_FOLDER}/c.${EXT}"
    cp "${TEMPLATE_FOLDER}/_.${EXT}" "${TARGET_CONTEST_FOLDER}/d.${EXT}"
    cp "${TEMPLATE_FOLDER}/_.${EXT}" "${TARGET_CONTEST_FOLDER}/e.${EXT}"
    cp "${TEMPLATE_FOLDER}/_.${EXT}" "${TARGET_CONTEST_FOLDER}/f.${EXT}"
    cp "${TEMPLATE_FOLDER}/_.${EXT}" "${TARGET_CONTEST_FOLDER}/g.${EXT}"
    cp "${TEMPLATE_FOLDER}/_.${EXT}" "${TARGET_CONTEST_FOLDER}/h.${EXT}"
    touch "${TARGET_CONTEST_FOLDER}/in"
    echo "done" 1>&2
  fi

  echo "opening ${CONTEST_NAME_PATH} ..." 1>&2
  code "${REPOSITORY_ROOT}/AtCoder.code-workspace" \
    "${LANGUAGE_ROOT}/_tips.${EXT}" \
    "${TARGET_CONTEST_FOLDER}/in" \
    "${TARGET_CONTEST_FOLDER}"/*."${EXT}"
  echo "done." 1>&2

  echo "${TARGET_CONTEST_FOLDER}" | clip.exe

  echo "" 1>&2
  echo "  パスをコピーしました" 1>&2
  echo "  ${TARGET_CONTEST_FOLDER}" 1>&2
}

usage() {
  cat <<- END 1>&2

[ common/open.sh ]
END
}

open "$@"
