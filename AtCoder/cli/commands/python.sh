#!/bin/sh

set -eu

cpp() {
  SUB_COMMAND="$1"
  case "$SUB_COMMAND" in
    r|run)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/python/run.sh"
    ;;

    rin)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/python/rin.sh"
    ;;

    mono)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/common/mono.sh python py"
    ;;

    t|temp|template)
      SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/common/template.sh python py"
    ;;

    h|help|usage)
      usage
      exit
    ;;

    *)
      # これだけ引数がフォルダ名を示すので、別の処理にする
      CURRENT_DIR_PATH="$CURRENT_DIR_PATH" \
      REPOSITORY_ROOT="$REPOSITORY_ROOT" \
      "${COMMAND_ROOT}/common/open.sh" python py "$@"
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

[ python.sh ]

  atc py run c            pythno3 c.py
  atc py rin c            pythno3 c.py < in
  atc py abc 123          abc/123 を開く
  atc py mono abc123-d    mono/abc123-d を開く
END
}

cpp "$@"
