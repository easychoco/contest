#!/bin/sh

set -eu

run() {
  # 抽出対象
  CPP="cpp"
  PY="PY"

  LANG=$(echo "$CURRENT_DIR_PATH" | sed -r "s/.*\/AtCoder\/(${CPP}|${PY})\/.*/\1/")
  case "$LANG" in
    "$CPP") run_cpp "$@" ;;
    "$PY") run_python "$@" ;;
    *)
      echo "unknown: ${LANG}"
      usage
    ;;
  esac
}

run_cpp() {
  if [ ! -e "$CURRENT_DIR_PATH"/a.out ]; then
    echo '  not found:' 1>&2
    echo "    ${CURRENT_DIR_PATH}/a.out" 1>&2
    exit
  fi

  "$CURRENT_DIR_PATH"/a.out
}

run_python() {
  if [ ! $# -eq 1 ]; then 
    echo "  you need arg" 1>&2
    usage
    exit
  fi

  if [ ! -e "${CURRENT_DIR_PATH}/${1}" ]; then
    echo '  not found:' 1>&2
    echo "    ${CURRENT_DIR_PATH}/${1}" 1>&2
    usage
    exit
  fi

  python3 "${CURRENT_DIR_PATH}/${1}"
}

usage() {
  cat <<- END 1>&2
      いまいるディレクトリを解析して、プログラムを実行する

      [C++] atc run
      [Python] atc run a
END
}

run "$@"
