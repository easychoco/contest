#!/bin/sh

set -eu

cp() {
  # 引数がないときはさようなら
  if [ $# -lt 2 ]; then
    usage && return 1
  fi

  if [ "$1" = 'mono' ]; then
    SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/cp/mono.sh
  else
    SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/cp/open.sh
  fi

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
