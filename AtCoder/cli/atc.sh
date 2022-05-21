#!/bin/sh

set -eu

atc() {
  CURRENT_DIR_PATH=$(pwd)

  REPOSITORY_ROOT=$(
    cd "$(dirname "$0")/.."
    pwd
  )

  COMMAND_ROOT="${REPOSITORY_ROOT}/cli/commands"

  if [ $# -eq 0 ]; then
    usage
    exit
  fi

  LANG=$(guess_lang "$CURRENT_DIR_PATH")
  if [ "$CURRENT_DIR_PATH" = "$LANG" ]; then
    echo "directory meybe wrong."
    usage
    return 1;
  fi

  SUB_COMMAND="$1"
  shift
  case "$SUB_COMMAND" in
    # C++
    c)   SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/cpp.sh" ;;
    cp)  SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/cpp.sh" ;;
    cpp) SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/cpp.sh" ;;
    gg)  SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/cpp.sh gg" ;;

    # Python
    p)   SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/python.sh" ;;
    py)  SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/python.sh" ;;
    python)  SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/python.sh" ;;

    # run program
    r)   SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/${LANG}/run.sh" ;;
    run) SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/${LANG}/run.sh" ;;
    rin) SUBCOMMAND_SCRIPT="${COMMAND_ROOT}/${LANG}/rin.sh" ;;

    *) usage ;;
  esac

  CURRENT_DIR_PATH="$CURRENT_DIR_PATH" \
  REPOSITORY_ROOT="$REPOSITORY_ROOT" \
  COMMAND_ROOT="$COMMAND_ROOT" \
  $SUBCOMMAND_SCRIPT "$@"
}

guess_lang() {
  # 抽出対象
  CPP="cpp"
  PY="PY"

  LANG=$(echo "$CURRENT_DIR_PATH" | sed -r "s/.*\/AtCoder\/(${CPP}|${PY}).*/\1/")
  echo "$LANG"
}

usage() {
  cat <<- END 1>&2
  
  C++:
    cp abc xxx         [C++] ABCxxx を VSCode で開く
    cp arc xxx         [C++] ARCxxx を VSCode で開く
    cp agc xxx         [C++] AGCxxx を VSCode で開く
    cp mono xxx        [C++] xxx.cpp という名前のファイルを mono フォルダに作って VSCode で開く
    gg xxx             [C++] ./xxx.cpp をコンパイルする
    run / r            [C++] ./a.out
    rin / rin          [C++] ./a.out < in
  
  Python:
    py abc xxx         [Python] ABCxxx を VSCode で開く
    py arc xxx         [Python] ARCxxx を VSCode で開く
    py agc xxx         [Python] AGCxxx を VSCode で開く
    py mono xxx        [Python] xxx.py という名前のファイルを mono フォルダに作って VSCode で開く
    run a / r a        [Python] python a.py
    rin a              [Python] python a.py < in
  
END
}

atc "$@"
