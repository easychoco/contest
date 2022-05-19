#!/bin/sh

set -eu

atc() {
  REPOSITORY_ROOT=$(
      cd "$(dirname "$0")/.."
      pwd
  )

  COMMAND_ROOT="$REPOSITORY_ROOT"/cli/commands

  if [ $# -eq 0 ]; then
      usage
      exit
  fi

  SUB_COMMAND=$1
  shift
  case "$SUB_COMMAND" in
    # C++
    cp) SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/cp.sh;;
    a) SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/a.sh ;;
    ain) SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/ain.sh ;;

    # Python
    py) SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/py.sh ;;
    p) SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/p.sh ;;
    pin) SUBCOMMAND_SCRIPT="$COMMAND_ROOT"/pin.sh ;;
    *) usage ;;
  esac

  REPOSITORY_ROOT="$REPOSITORY_ROOT" \
  COMMAND_ROOT="$COMMAND_ROOT" \
  $SUBCOMMAND_SCRIPT "$@"
}

usage() {
  cat <<- END 1>&2
  
  C++:
    cp abc xxx       [C++] ABCxxx を VSCode で開く
    cp arc xxx       [C++] ARCxxx を VSCode で開く
    cp agc xxx       [C++] AGCxxx を VSCode で開く
    cp mono xxx      [C++] xxx.cpp という名前のファイルを mono フォルダに作って VSCode で開く
    a                [C++] ./a.out
    ain              [C++] ./a.out < in
  
  Python:
    py abc xxx       [Python] ABCxxx を VSCode で開く
    py arc xxx       [Python] ARCxxx を VSCode で開く
    py agc xxx       [Python] AGCxxx を VSCode で開く
    py mono xxx      [Python] xxx.py という名前のファイルを mono フォルダに作って VSCode で開く
    p a              [Python] python a.py
    pin a            [Python] python a.py < in
  
END
}

atc "$@"
