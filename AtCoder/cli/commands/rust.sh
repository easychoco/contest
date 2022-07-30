#!/bin/sh

set -eu

rust() {

  if [ $# -eq 0 ]; then
    "${COMMAND_ROOT}/atc.sh" run
    exit
  fi

  SUB_COMMAND="$1"
  case "$SUB_COMMAND" in
    cg|cargo)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/rust/cargo.sh"
    ;;
    r|run)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/rust/run.sh"
    ;;
    rin)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/rust/rin.sh"
    ;;
    mono)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/common/mono.sh rust rs"
    ;;
    t|temp|template)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/common/template.sh rust rs"
    ;;
    h|help|usage)
      usage
      exit
    ;;
    *)
      # これだけ引数がフォルダ名を示すので、別の処理にする
      CURRENT_DIR_PATH="$CURRENT_DIR_PATH" \
      REPOSITORY_ROOT="$REPOSITORY_ROOT" \
        "${COMMAND_ROOT}/common/open.sh" rust rs "$@"
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

[ rust.sh ]

  atc rust gg c             c.rs をコンパイルする
  atc rust run              a.out を実行する
  atc rust abc 123          abc/123 を開く
  atc rust mono abc123-d    mono/abc123-d を開く
END
}

rust "$@"
