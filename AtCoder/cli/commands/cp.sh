#!/bin/sh

set -eu

cp() {
  SUB_COMMAND="$1"
  case "$SUB_COMMAND" in
    gg) SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/cp/gg.sh;;
    r)   SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/run.sh ;;
    run) SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/run.sh ;;
    rin) SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/rin.sh ;;
    mono) SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/cp/mono.sh ;;
    *)
      # これだけ引数がフォルダ名を示すので、別の処理にする
      CURRENT_DIR_PATH="$CURRENT_DIR_PATH" \
      REPOSITORY_ROOT="$REPOSITORY_ROOT" \
      "$COMMAND_ROOT"/cp/open.sh "$@"
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

  you need args:
    ex)
      atc cp abc 123
      atc cp mono abc123-d
END
}

cp "$@"
