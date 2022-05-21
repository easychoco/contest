#!/bin/sh

set -eu

cpp() {
  SUB_COMMAND="$1"
  case "$SUB_COMMAND" in
    gg) SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/cpp/gg.sh" ;;
    r)   SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/cpp/run.sh" ;;
    run) SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/cpp/run.sh" ;;
    rin) SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/cpp/rin.sh" ;;
    mono) SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/mono.sh cpp cpp" ;;
    h|help|usage)
      usage
      exit
    ;;
    *)
      # これだけ引数がフォルダ名を示すので、別の処理にする
      CURRENT_DIR_PATH="$CURRENT_DIR_PATH" \
      REPOSITORY_ROOT="$REPOSITORY_ROOT" \
      "${COMMAND_ROOT}/open.sh cpp cpp" "$@"
      exit
    ;;
  esac

  shift
  CURRENT_DIR_PATH="$CURRENT_DIR_PATH" \
  REPOSITORY_ROOT="$REPOSITORY_ROOT" \
  COMMAND_ROOT="$COMMAND_ROOT" \
  $SUBCOMMAND_SCRIPT "$@"
}

usage() {
  cat <<- END 1>&2

  atc cpp gg c             c.cpp をコンパイルする
  atc cpp run              a.out を実行する
  atc cpp abc 123          abc/123 を開く
  atc cpp mono abc123-d    mono/abc123-d を開く
END
}

cpp "$@"
